# Computer Graphics Programs

- Modified and Simplified as Much as Possible.

## Execution
```shell
# Compile
 cc foo.c -o foo -lGL -lGLU -lglut

 # Run
 ./file

```
- `-o` flag is optional.
- without it it defaults to a.out or similar file
- some old compilers require you to grant executable permission
```shell
chmod +x foo
```

## Prerequisite
*Packages*: May Require Root Privileges `sudo` | `doas`
- Archlinux Based Distro
```shell
pacman -S mesa glu freeglut
```

- Debian Based Distro
```shell
apt-get install libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
```

- Fedora Based Distro
```shell
dnf install mesa-libGL-devel mesa-libGLU-devel freeglut-devel
```
