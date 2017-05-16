------------
Build
------------

```
docker build -t mlsd .
```

This will build a docker image named ```mlsd```.

------------
Run
------------

Supposing your data is under directory of ```TO_BE_FILLED``` (which should be better filled as an absolute path), you use can call ```mlsd``` in the following way.

```
docker run --rm -ti -v TO_BE_FILLED:TO_BE_FILLED mlsd -d TO_BE_FILLED -i TO_BE_FILLED/images.txt
```

Note, the ```-v``` is the ```docker``` option to mount (local) volumes (to containers).
