import os
import shutil
import re

# 在当前目录下查找文件
for filename in os.listdir("."):
    # 检查文件名是否以数字和"."开头，并以".cpp"结尾
    if re.match(r"^[0-9]+\..*\.cpp$", filename):
        # 获取文件名的前缀（去掉.cpp后缀）
        prefix = filename.rsplit(".", 1)[0]
        # 获取数字部分
        num = prefix.split(".", 1)[0]
        # 获取后缀部分（去掉数字和"."的前缀）
        suffix = prefix.split(".", 1)[1]

        # 创建新目录
        new_dir = os.path.join("cpp", f"{num}.{suffix}")

        # 如果新目录已存在，删除源文件
        if os.path.exists(new_dir):
            os.remove(filename)
        else:
            # 否则，移动并重命名文件
            os.makedirs(new_dir, exist_ok=True)
            shutil.move(filename, os.path.join(new_dir, "solution.cpp"))
