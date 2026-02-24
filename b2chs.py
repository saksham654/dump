# Assumtions:
# 1 Sector = 512 Bytes
# 1 Head = 63 Sectors
# 1 Cylinder = 255 Heads
# remaining show Bytes that cannot completely fill a sector

import math

def chs(bytes):
     sectors = math.floor(bytes/512)
     remaining = bytes - sectors * 512
     heads = math.floor(sectors/63)
     sectors = sectors - heads * 63
     cylinders = math.floor(heads/255)
     heads = heads - cylinders * 255
     print("\n",cylinders,"C ",heads,"H ",sectors,"S + ",remaining,"B")

# Bytes to MiB ( factor of 1024 )
def b2mib(bytes):
	return bytes / ( 1024 * 1024 )

# MiB to Bytes ( factor of 1024 )
def mib2b(mib):
	return mib * 1024 * 1024



