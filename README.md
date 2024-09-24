# *`FDF`*
## About
3D wireframe rendering application that transforms 2D elevation maps into 3d landscapes,
creating a wireframe representation of the terrain.
using the school graphic library <a href="/lib/minilibx_macos/_README_">Minilibx</a>

## Examples
- ### simple file format
```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

results in

![](/images/42.png)



- ### different heights
	```
	maps/old_maps/10-2.fdf
	```
![](/images/10-2.png)




- ### bigger map

	``` 
	maps/new_maps/MGDS_CORDILLERA_DE_LOS_ANDES_OCEAN0_S.fdf
	```
![](/images/MGDS_CORDILLERA_DE_LOS_ANDES_OCEAN0_S.png)




- ### complex maps

``` 
	maps/new_maps/nerd_colored.fdf
```
![](/images/nerd_colored.png)
```
	maps/new_maps/hydrochoerus_hydrochaeris_2.0.fdf 
```
![](/images/hydrochoerus_hydrochaeris_2.0.png)
```
maps/new_maps/hydrochoerus_hydrochaeris.fdf 
```
![](/images/hydrochoerus_hydrochaeris.png)
