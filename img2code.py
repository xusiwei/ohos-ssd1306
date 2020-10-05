#!/usr/bin/env python3
import cv2
import sys
import os

DEBUG = False
# DEBUG = True
TARGET_WIDTH = 128
TARGET_HEIGHT = 64
PIXEL_PER_BYTE = 8
PIXEL_THRESHOUD = 128.0

def ConvertFrame(frame):
    byteArray = []
    # bitStream = [] # for debug
    count, value = 0, 0
    for r in range(TARGET_HEIGHT):
        for c in range(TARGET_WIDTH):
            px = frame[r, c]
            gray = sum(px)/len(px) # 灰度值
            bit = 1 if gray > PIXEL_THRESHOUD else 0 # 二值化
            # bitStream.append(bit) # for debug
            if count < PIXEL_PER_BYTE:
                value = (value << 1) + bit # 多个二值化像素值拼接为一个字节值
                count += 1
            if count == PIXEL_PER_BYTE:
                byteArray.append(value)
                count, value = 0, 0
                # if DEBUG and value != 0 and value != 0xFF:
                #     print('0x%02X = %s, %d, %d' % (value, str(bitStream[-8:]), r, c))
    return byteArray

def main():
    if len(sys.argv) < 3:
        print("Usage: {} input outdir".format(sys.argv[0]))
        exit(-1)

    imgPath = sys.argv[1]
    outdir = sys.argv[2]
    imgFile = os.path.split(imgPath)[-1]
    imgBase = imgFile.split('.')[-2]
    codeFile = os.path.join(outdir, imgBase + '.c')
    if not os.path.exists(outdir):
        os.mkdir(outdir)

    rawFrame = cv2.imread(imgPath) # 加载图片
    frame = cv2.resize(rawFrame, (TARGET_WIDTH, TARGET_HEIGHT)) # 缩放
    byteArray = ConvertFrame(frame) # 转为目标格式的数组

    with open(codeFile, 'w+') as f: # 输出到.c文件
        f.write('const unsigned char ' + imgBase + '[] = {\n')
        for i in range(len(byteArray)):
            v = byteArray[i]
            sep = '\n' if (i+1) % (TARGET_WIDTH/PIXEL_PER_BYTE) == 0 else ' '
            f.write('0x%02X,%s' % (v, sep))
        f.write('};\n')
    print(imgFile, '=>', codeFile, 'done!')

if __name__ == "__main__":
    main()
