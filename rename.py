import os


def delete_icloud_files(dir_path="."):
    # 遍历指定目录和其所有子目录
    for root, dirs, files in os.walk(dir_path):
        for file in files:
            # 如果文件以".icloud"结尾，删除它
            if file.endswith(".icloud"):
                file_path = os.path.join(root, file)
                os.remove(file_path)
                print(f"Deleted file: {file_path}")


# 调用函数删除当前目录及其所有子目录下的".icloud"文件
delete_icloud_files(".")
