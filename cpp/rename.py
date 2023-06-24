import os
import shutil
import re


def process_files_in_directory(dir_path="."):
    # 在指定目录下查找文件
    for filename in os.listdir(dir_path):
        file_path = os.path.join(dir_path, filename)
        # 检查文件名是否以数字和"."开头，并以".cpp"结尾
        if re.match(r"^[0-9]+\..*\.cpp$", filename):
            # 获取文件名的前缀（去掉.cpp后缀）
            prefix = filename.rsplit(".", 1)[0]
            # 创建新目录
            new_dir = os.path.join(dir_path, prefix)
            # 如果新目录已存在，删除源文件
            if os.path.exists(new_dir):
                os.remove(file_path)
            else:
                # 否则，移动并重命名文件
                os.makedirs(new_dir, exist_ok=True)
                shutil.move(file_path, os.path.join(new_dir, "solution.cpp"))


# 调用函数处理当前目录下的文件
process_files_in_directory(".")
