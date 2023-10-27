cd /build-volume
echo "Cloning qmk firmware repo"
git clone https://github.com/qmk/qmk_firmware.git
cd /build-volume/qmk_firmware
echo "Activating venv"
. /opt/venv/bin/activate
echo "Installing pip requirements"
pip install -r /build-volume/qmk_firmware/requirements.txt
echo "Making git submodule"
make git-submodule
echo "QMK Setup"
qmk setup -y
echo "Create keymap"
qmk new-keymap -kb keebio/iris/rev8 -km matthewspangler
cp /build-volume/custom-keymap/* /build-volume/qmk_firmware/keyboards/keebio/iris/keymaps/matthewspangler
echo "Compile firmware"
qmk compile -kb keebio/iris/rev8 -km matthewspangler
ls
pwd
