# http://www.visuality.pl/posts/cs-lessons-001-working-with-binary-files

data = File.read("boom.nap")
data.encoding
data.unpack("C*")