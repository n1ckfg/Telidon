# http://www.visuality.pl/posts/cs-lessons-001-working-with-binary-files
# Begin: ESC 25 41 [27 25 41] ... End: ESC 25 40 [27 25 40]

data = File.read("boom.nap")
data.encoding
data.unpack("C*")