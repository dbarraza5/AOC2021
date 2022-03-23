# AOC2021
Advent of Code is an Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like. People use them as a speed contest, interview prep, company training, university coursework, practice problems, or to challenge each other.  

https://adventofcode.com/  
###  Day 1: Sonar Sweep 
https://adventofcode.com/2021/day/1  
[notebook Dia 1](Dia1/Dia1.ipynb)

###  Day 2: Dive!
https://adventofcode.com/2021/day/2  
[notebook Dia 2](Dia1/Dia2.ipynb)

###  Day 3: Binary Diagnostic
https://adventofcode.com/2021/day/3
[notebook Dia 3](Dia1/Dia3.ipynb)

El archivo contenía números en binarios y al tratar de cargarlo con pandas convertía la cadena en números borrando los ceros que estuvieran por delante de cualquier número mayor a cero.  

"000001110001" => 1110001   
  
Solución: indicarle a pandas el tipo de dato que es la columna antes de cargarlo

```python
df = pd.read_csv("noise.csv", dtype={"report": str})
```


### Day 4: Giant Squid
https://adventofcode.com/2021/day/4  
[notebook Dia 4](Dia1/Dia4.ipynb)
  
Crear un array desde string  
```python
np.fromstring(l[0], sep = ',', dtype= int)
```

### Day 5: Hydrothermal Venture
https://adventofcode.com/2021/day/5
[notebook Dia 5](Dia1/Dia5.ipynb)

Problema: el dataset consiste en pares de coordenadas. Existe una separación entre el par de coordenadas “->”.
  
0,9 -> 5,9
  
 ```python
df = pd.read_csv("Hydrothermal.csv",sep="->",header=None, names=["p1", "p2"])
```
  
Solución:  dividir una columna en 2. 
  
 ```python
sp1 = df["p1"].str.split(",",n = 1, expand = True)
```


###  Day 8: Seven Segment Search
https://adventofcode.com/2021/day/8  
[notebook Dia 8](Dia1/Dia8.ipynb)

Limpiando la columna 
  
 ```python
df["target"]=df["target"].str.strip()
```
