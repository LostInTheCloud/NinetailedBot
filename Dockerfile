from archlinux/archlinux:base
run pacman -Syu gcc cmake make --noconfirm
copy . /app
workdir /app
run cmake . && make
cmd ["./NineTailedBot"]