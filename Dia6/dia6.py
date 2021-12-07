import pandas as pd
import numpy as np

f = open("Lanternfish.txt", "r")
raw = f.read()

peces_iniciales = np.fromstring(raw, sep = ',', dtype= int)
peces_iniciales

print(peces_iniciales[:10])

peces_actuales = np.copy(peces_iniciales)
for dia in range(256):
    if dia>0:
        idx_peces_0 = np.where(peces_actuales == 0)
        if idx_peces_0[0].size>0:
            peces_actuales[idx_peces_0] = 7
            peces_actuales=np.append(peces_actuales,
                                     np.full(idx_peces_0[0].size, 9, dtype=int))
    peces_actuales-=1
    #print(dia+1, peces_actuales)
print(peces_actuales.size)