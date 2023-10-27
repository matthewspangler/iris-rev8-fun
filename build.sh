echo "Copying keymap files to container volume"
mkdir -p ./build-volume/custom-keymap
cp keymap.c ./build-volume/custom-keymap/
cp rules.mk ./build-volume/custom-keymap/
cp config.h ./build-volume/custom-keymap/
echo "Building container"
podman build -t qmkbuild .
echo "Running container"
podman run -it --rm localhost/qmkbuild
#cp ./qmk_firmware/.build/keebio_iris_rev8_matthewspangler.uf2 ~/Desktop/keebio_iris_rev8_matthewspangler.uf2
echo "Moving binaries to output folder"
