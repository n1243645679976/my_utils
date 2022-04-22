import os
import librosa
import subprocess
from pathlib import Path
import sys
#_dir = '/mnt/md1/user_n124345679976/dataset/librispeech/LibriSpeech/'
_dir = sys.argv[1]
c = {}
d = []
e = {'.wav': 0, '.flac': 0}
for j,k,l in os.walk(_dir):
 for i in l:
   if i.endswith('.wav') or i.endswith('.WAV'):
    with open(j+'/'+i, 'rb') as f:
     a = f.read(24)
     b = f.read(4)
     _b = int.from_bytes(b, byteorder='little')
     if _b in c:
      c[_b]+=1
     else:
      c[_b]=1
  #   if _b == 22050:
  #    r = subprocess.check_output(['sox', '-v', '0.95', './wav/'+i , '-r', '16000', './wav16000/'+i])
    e['.wav'] += 1
   if i.endswith('.flac') or i.endswith('.FLAC'):
    with open(j+'/'+i, 'rb') as f:
     a = f.read(18)
     b = f.read(3)
     _b = int.from_bytes(b, byteorder='big')
     _b >>= 4
    if _b in c:
     c[_b] += 1
    else:
     c[_b] = 1
    e['.flac'] += 1
  
  #for i in d:
  # os.rename('./wav/'+i, './wav16000/'+i)
print(c)
print(e)
