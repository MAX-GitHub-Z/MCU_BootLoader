import  os
import  shutil

print(os.getcwd())
file_name = __file__
print(file_name)
os.chdir("../output/")#输出文件夹
new_path = os.getcwd()

os.chdir("../Project/Objects/")#目标文件
folder_path = os.getcwd()
print(folder_path)
files = os.listdir(folder_path)
for file in files:
    if file.endswith(".bin"):
        print("将文件"+file+"复制到"+new_path+"下")
        shutil.copy(file,new_path)
    if file.endswith(".hex"):
        print("将文件"+file+"复制到"+new_path+"下")
        shutil.copy(file,new_path)
    if file.endswith(".axf"):
        print("将文件"+file+"复制到"+new_path+"下")
        shutil.copy(file,new_path)