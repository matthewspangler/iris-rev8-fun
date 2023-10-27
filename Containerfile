FROM debian:stable-slim

# Install QMK prerequisites
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    clang-format \
    diffutils \
    gcc \
    unzip \
    wget \
    zip \
    avr-libc \
    binutils-arm-none-eabi \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    avrdude \
    teensy-loader-cli \
    libhidapi-hidraw0 \
    libusb-dev \
    ca-certificates \
    gcc unzip \
    wget \
    zip \
    gcc-avr \
    binutils-avr \
    avr-libc \
    dfu-programmer \
    dfu-util \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    make \
    python3 \
    python3-pip \
    python3-venv \
    git-core && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

ADD ./build-volume /build-volume
VOLUME ./build-volume
#WORKDIR /build-volume

COPY entry.sh .

RUN python3 -m venv /opt/venv
RUN . /opt/venv/bin/activate && \
    pip install qmk

CMD /entry.sh
