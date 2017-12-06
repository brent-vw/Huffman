import os
import time
import csv
import pandas

from subprocess import run, PIPE
from ggplot import *
from math import ceil, floor

from tqdm import tqdm


def join_args(program, alg_number, encode, size=0):
    alg_flag = '-t'
    encode_flag = '-c'
    decode_flag = '-d'
    size_flag = '-s'

    if encode:
        flag = encode_flag
    else:
        flag = decode_flag
    cmd = [program, alg_flag, str(alg_number), flag]

    if size!=0:
        cmd.extend([size_flag, str(size)])

    return cmd


def run_command(program, stdin, stdout):
    with open(stdin, 'rb') as new_in:
        with open(stdout, 'wb') as new_out:
            proc_info = run(program, stdin=new_in, stdout=new_out, stderr=PIPE, shell=False, check=True)
            new_out.flush()
    return proc_info


def current_time_milis():
    return int(round(time.time() * 1000))


def round(num, places=0, direction=floor):
    return direction(num * (10 ** places)) / float(10 ** places)


def delete_folders():
    for folder in ['ratios', 'duur', 'duur/encode', 'duur/decode']:
        for the_file in os.listdir('grafieken/' + folder):
            file_path = os.path.join('grafieken/' + folder, the_file)
            try:
                if os.path.isfile(file_path):
                    os.unlink(file_path)
            except Exception as e:
                print(e)


def encode_all():
    with tqdm(total=(len(range(1, algs))*len(files)*2), ncols=100) as pbar:
        with open('encoding_times.csv', 'w') as encoding_times_file:
            encoding_times = csv.writer(encoding_times_file)
            encoding_times.writerow(["Algorithm", "Operation", "File", "Size", "Time (ms)"])

            with open('file_sizes.csv', 'w') as file_sizes_file:
                file_sizes = csv.writer(file_sizes_file)
                file_sizes.writerow(["Algorithm", "File", "Size", "Ratio"])

                for alg in range(1, algs):
                    for file in files:
                        file_path = folder_name + file
                        encode = join_args(program, alg, True)
                        decode = join_args(program, alg, False)

                        fileName = file.split('.')[0] + '_'
                        extension = '.' + file.split('.')[1]
                        encoded_name = 'encoded/' + fileName + 'encoded' + '_' + names[alg - 1]
                        decoded_name = 'decoded/' + fileName + 'decoded' + '_' + names[alg - 1] + extension

                        pbar.set_description('Currently encoding ' + file + ' with ' + names[alg - 1])
                        error = True
                        start = current_time_milis()
                        while error:
                            try:
                                run_command(encode, file_path, encoded_name)
                            except Exception:
                                print("error " + str(alg))
                                start = current_time_milis()
                                continue
                            error = False
                        end = current_time_milis()
                        encoding_time = str(end - start)
                        pbar.update(1)

                        pbar.set_description('Currently decoding ' + file + ' with ' + names[alg - 1])
                        error = True
                        start = current_time_milis()
                        while error:
                            try:
                                run_command(decode, encoded_name, decoded_name)
                            except Exception:
                                print("error " + str(alg))
                                start = current_time_milis()
                                continue
                            error = False
                        end = current_time_milis()
                        decoding_time = str(end - start)
                        pbar.update(1)

                        original_size = os.path.getsize(file_path)
                        encoded_size = os.path.getsize(encoded_name)

                        file_sizes.writerow([names[alg - 1], file, str(encoded_size), str(original_size / encoded_size)])
                        encoding_times.writerow([names[alg - 1], 'encode', file, str(original_size), encoding_time])
                        encoding_times.writerow([names[alg - 1], 'decode', file, str(original_size), decoding_time])

    for folder in ['decoded', 'encoded']:
        for the_file in os.listdir(folder):
            file_path = os.path.join(folder, the_file)
            try:
                if os.path.isfile(file_path):
                    os.unlink(file_path)
            except Exception as e:
                print(e)


def build_sizes_graphs():
    folder = 'grafieken/ratios/'
    file_sizes = pandas.read_csv('file_sizes.csv')

    for file in files:
        current_sizes = file_sizes[file_sizes['File'].isin([file])]
        highest = round(current_sizes['Ratio'].max(), 1, ceil)
        lowest = round(current_sizes['Ratio'].min(), 1, floor)

        plot = ggplot(aes(x='Algorithm', weight='Ratio'), data=current_sizes) + \
               geom_bar(stat="identity", fill=bar_color, width=0.3) + \
               ylim(lowest, highest) + \
               ylab("Ratio (input/output)") + \
               ggtitle("Compressieratio voor " + file + " (hoger is beter)")

        plot.save(folder + file.split('.')[0] + '.pdf')


def sliding_size_graphs():
    folder = grafieken
    sliding_size = pandas.read_csv()


def build_times_graphs():
    folder = 'grafieken/duur/'
    encoding_times = pandas.read_csv('encoding_times.csv')
    types = ['encode', 'decode']
    dic = {
        types[0]: 'encoderen',
        types[1]: 'decoderen'
    }

    for type in types:
        current_type = encoding_times[encoding_times['Operation'].isin([type])]
        for file in files:
            current_times = current_type[current_type['File'].isin([file])]
            highest = current_times['Time (ms)'].max() + 1
            lowest = current_times['Time (ms)'].min() - 1

            plot = ggplot(aes(x='Algorithm', weight='Time (ms)'), data=current_times) + \
                   geom_bar(stat="identity", fill=bar_color, width=0.3) + \
                   ylim(lowest, highest) + \
                   ylab("Duur (ms)") + \
                   ggtitle('Duur voor het ' + dic[type] + ' van ' + file + " (lager is beter)")

            plot.save(folder + type + '/' + file.split('.')[0] + '.pdf')

    for type in types:
        current_type = encoding_times[encoding_times['Operation'].isin([type])]
        for binary in [True, False]:
            if binary:
                name = 'textbestanden'
                current_time = current_type[current_type['File'].str.match('.*\.txt$')]
            else:
                name = 'binaire bestanden'
                current_time = current_type[current_type['File'].str.match('.*[^t][^x][^t]$')]

            plot = ggplot(aes(x='Size', y='Time (ms)', color='Algorithm'), data=current_time) + \
                   geom_point(position='jitter') + \
                   stat_smooth(method='loes', se=False, alpha=.5) + \
                   ylab("Duur (ms)") + \
                   xlab('Bestandsgrootte (bytes)') + \
                   ggtitle('Duur ifv. bestandsgrootte bij ' + dic[type] + ' voor ' + name)
            plot.save(folder+type+'_'+name.replace(' ', '_')+'.pdf')


def compare_sizes(type, sizes=None):
    if sizes is None:
        sizes = [128, 256, 512, 1024, 2048]

    with tqdm(total=(len(files)*2*len(sizes)), ncols=100) as pbar:
        with open(names[type-1]+'_averages.csv', 'w') as block_averages_file:
            block_averages = csv.writer(block_averages_file)
            block_averages.writerow(["size", "type" ,"Time (ms)", "Ratio"])
            alg = type
            for size in sizes:
                for file in files:
                    file_path = folder_name + file
                    encode = join_args(program, alg, True, size=size)
                    decode = join_args(program, alg, False, size=size)

                    fileName = file.split('.')[0] + '_'
                    extension = '.' + file.split('.')[1]
                    encoded_name = 'encoded/' + fileName + 'encoded' + '_' + names[alg - 1]
                    decoded_name = 'decoded/' + fileName + 'decoded' + '_' + names[alg - 1] + extension

                    if extension == 'txt':
                        type = 'tekst'
                    else:
                        type = 'binair'

                    pbar.set_description('Currently encoding ' + file + ' with size ' + str(size))
                    error = True
                    start = current_time_milis()
                    while error:
                        try:
                            run_command(encode, file_path, encoded_name)
                        except Exception:
                            print("error " + str(alg))
                            start = current_time_milis()
                            continue
                        error = False
                    end = current_time_milis()
                    encoding_time = str(end - start)
                    pbar.update(1)

                    pbar.set_description('Currently decoding ' + file + ' with size ' + str(size))
                    error = True
                    start = current_time_milis()
                    while error:
                        try:
                            run_command(decode, encoded_name, decoded_name)
                        except Exception:
                            print("error " + str(alg))
                            start = current_time_milis()
                            continue
                        error = False
                    end = current_time_milis()
                    decoding_time = str(end - start)
                    pbar.update(1)

                    original_size = os.path.getsize(file_path)
                    encoded_size = os.path.getsize(encoded_name)

                    block_averages.writerow([str(size), type, str(encoding_time+decoding_time),
                                             str(original_size / encoded_size)])
    for folder in ['decoded', 'encoded']:
        for the_file in os.listdir(folder):
            file_path = os.path.join(folder, the_file)
            try:
                if os.path.isfile(file_path):
                    os.unlink(file_path)
            except Exception as e:
                print(e)


def build_opt_graph(name, readable_name=None, sizes=None):
    if sizes is None:
        sizes = [128, 256, 512, 1024, 2048]

    if readable_name is None:
        readable_name = name

    folder = 'grafieken/duur/'
    window_sizes = pandas.read_csv(name+'_averages.csv')

    time = []
    ratio = []

    for size in sizes:
        time.append(float(window_sizes[window_sizes['size'].isin([size])][['Time (ms)']].mean()))
        ratio.append(float(window_sizes[window_sizes['size'].isin([size])][['Ratio']].mean()))

    df = pandas.DataFrame.from_records({'size': sizes, 'time': time, 'ratio': ratio})

    plot = ggplot(aes(x='size', weight='time', color='type'), data=df) + \
           geom_bar(stat="identity", fill=bar_color, width=0.3) + \
               ylab("Gemiddelde uitvoeringstijd (encode + decode)") + \
               xlab(readable_name+" size") + \
               ggtitle("Gemiddelde uitvoeringstijd voor verschillende "+readable_name+" sizes")
    plot.show()

    plot1 = ggplot(aes(x='size', weight='ratio', color='type'), data=df) + \
           geom_bar(stat="identity", fill=bar_color, width=0.3) + \
               ylab("Ratio (in_size/decoded_size)") + \
               xlab(readable_name+ " size") + \
               ggtitle("Gemiddelde ratio voor verschillende "+readable_name+" sizes")
    plot1.show()


folder_name = 'testbestanden/'
algs = 6
program = './huffman'
files = os.listdir(folder_name)
names = ['static', 'adaptive', 'sliding', 'two_pass', 'block']
bar_color = '#5cbae6'

#Clear console
os.system('cls' if os.name == 'nt' else 'clear')

delete_folders()

# encode_all()
# build_sizes_graphs()
# build_times_graphs()

block_sizes = [16, 128, 512, 1024, 2048, 8192, 16384, 32768]
window_sizes = [16, 128, 512, 1024, 2048, 8192, 16384, 32768]
compare_sizes(3, sizes=window_sizes)
compare_sizes(4, sizes=block_sizes)
build_opt_graph(names[2], readable_name='window', sizes=window_sizes)
build_opt_graph(names[3], readable_name='block', sizes=block_sizes)
