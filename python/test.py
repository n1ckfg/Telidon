# https://stackoverflow.com/questions/1035340/reading-binary-file-and-looping-over-each-byte
# https://stackoverflow.com/questions/7396849/convert-binary-to-ascii-and-vice-versa
# https://www.devdungeon.com/content/working-binary-data-python
# Begin: ESC 25 41 [27 25 41] ... End: ESC 25 40 [27 25 40]
import binascii

def text_to_bits(text, encoding='utf-8', errors='surrogatepass'):
    bits = bin(int(binascii.hexlify(text.encode(encoding, errors)), 16))[2:]
    return bits.zfill(8 * ((len(bits) + 7) // 8))

def text_from_bits(bits, encoding='utf-8', errors='surrogatepass'):
    n = int(bits, 2)
    return int2bytes(n).decode(encoding, errors)

def int2bytes(i):
    hex_string = '%x' % i
    n = len(hex_string)
    return binascii.unhexlify(hex_string.zfill(n + (n & 1)))

def octalToDecimal(octal):  
    decimal = 0    
    n = 0
    while True:    
      if (octal == 0):   
        break    
      else:    
          temp = octal%10    
          decimal += temp*pow(8, n)    
          octal = octal/10    
          n += 1      
    return decimal     

def decimalToOctal(decimal):
    counter = 0
    octal = 0
    while decimal !=0:
        temp = int((decimal%8) * pow(10, counter))
        counter += 1
        octal += temp
        decimal /= 8
    return octal

def file_byte_iterator(path):
    with open(path, 'rb') as file:
        for chunk in file:
            for byte in chunk:
                yield byte

napStr = ""

for byte in file_byte_iterator("boom.nap"):
    b = ord(byte)
    napStr += str(b) + ", "

print(napStr)