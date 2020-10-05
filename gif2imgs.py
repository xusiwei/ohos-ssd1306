#!/usr/bin/env python3
import os
import sys
from PIL import Image

if len(sys.argv) < 2:
	print('Usage: {} gif outdir'.format(sys.argv[0]))
	exit(-1)

gifimg = sys.argv[1]
outdir = sys.argv[2]

im = Image.open(gifimg)
if not os.path.exists(outdir):
	os.mkdir(outdir)

i = 0
try:
	while True:
		im.seek(i)
		im.save(os.path.join(outdir, 'frame' + str(i) + '.png'))
		i += 1
except:
	pass
print('images:', i)
