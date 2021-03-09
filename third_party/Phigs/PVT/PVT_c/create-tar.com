# generate tar file of C-PVT from current directory; invoke
# with "source" or "do"

tar -cvf - . | compress  > ~/pvt/PVT_c.tar.Z
