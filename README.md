# Huawei P9 Plus (VIENNA) Android OREO EMUI 8.0 Kernel v4.4.23 Opensource from Huawei
### [newbit @ xda-developers](https://forum.xda-developers.com/m/newbit.1350876/)
Opensource Code for the Huawei P9 Plus AL10 Kernel

### Get some packages
`sudo apt-get install build-essential libssl-dev libncurses5-dev bison flex libqt4-dev pkg-config`

### Get the Toolchain
`./configure_gcc_toolchain`

### Exports
`source .exports`

### Compile it
`make ARCH=arm64 distclean`\
`rm ../out -Rf && make clean && make mrproper && mkdir ../out`\
`make ARCH=arm64 O=../out merge_hi3650_defconfig`\
`make ARCH=arm64 O=../out xconfig`\
`time make ARCH=arm64 O=../out -j$(nproc)`

### Links
* [consumer huawei opensource](https://consumer.huawei.com/en/opensource)
* [VIE-AL10_OREO_EMUI8.0_opensource.tar.gz](http://download-c1.huawei.com/download/downloadCenter?downloadId=99968&version=425783&siteCode=worldwide)
* [Prebuild GCC Toolchain Android NDK 17c](https://dl.google.com/android/repository/android-ndk-r17c-linux-x86_64.zip)

### Hints for Cherry Picking from AOSP
`git remote add kernel_common https://github.com/aosp-mirror/kernel_common.git`\
`git fetch kernel_common android-4.4-o`\
`git log kernel_common/android-mainline --pretty=format:"%H %ad: %s" --follow -- drivers/usb/gadget/function/uvc_configfs.c > ../uvc_configfs-follow-commits.txt`\
`git fetch kernel_common android-4.4-o`\
`git log kernel_common/android-4.4-o --pretty=format:"%H %ad: %s" --after="2015-01-01" --follow -- drivers/usb/gadget > ../usb-gagdet-4.4.o.commits.txt`\
`git config --int merge.renameLimit 999999`\
`git config --int diff.renameLimit 999999`\
`git cherry-pick --allow-empty-message --keep-redundant-commits <commit id>`\
`git cherry-pick --allow-empty-message --keep-redundant-commits -m 1 <commit id>`\
`patch -p1 -i ../patches/`\
`git checkout -b uvc-gadget`\
`git push -d origin uvc-gadget`\
`patch -R -p1 < ./patches/`\
`git log kernel_common/android-mainline --pretty=format:"%H %ad: %s" --after="2014-11-27" --follow -- drivers/usb/gadget/function/uvc_configfs.c > ../uvc_configfs-commits.txt`\
