### INTERACTIVE NAPLPS DEMO ###
### Interact with NAPLPS Client (PP3) over a serial connection ###
### John Durno, January 2017 ###
### Added auto-advance April 2017 ###
### Added chunks April 2017 ###
### Added quit (q) April 2017 ###
### Added timeout (auto=M) May 2017 ###

## Imports ###
import collections
import serial
import time
from threading import Thread
from Queue import Queue
import sys


### Data dictionary ###
def rec_dd():
    return collections.defaultdict(rec_dd)

j = rec_dd()

# DICT PARAMs #
# fn - name of file to load
# auto - auto-advance to the next slide? Values Y, N, M
     # Y=Yes, N=No, M=Maybe [if no input received before timeout]
# goto - cmd to invoke for auto-advance, refers to numbers in NAPLPS frames
# renderwait - interval to pause after file is sent, in seconds
# inputwait - how long to wait for input when auto=M
# chunk - number of bytes to send before pausing, 0=send whole file with no breaks
# chunkwait - pause interval before sending the next chunk in seconds, 0=no wait
# cmd - nested dict of one or more commands indicating file to move to next

# NOTES re PARAMS
# cmd can be entered either by auto-advance(goto) or through user input
# files that exceed some undetermined maximum size have transmission problems
# use chunk feature to sends parts of files as chunks
# use chunkwait to specify delays between chunks
# wait and chunkwait values are based on manual timings of file renderings

### INTERACTIVE NAPLPS DEMO ###

j['idemo010']['fn'] = 'idemo.010' 	
j['idemo010']['auto'] = 'N' 		
j['idemo010']['goto'] = '1' 		
j['idemo010']['renderwait'] = 4
j['idemo010']['inputwait'] = 0
j['idemo010']['chunksize'] = 0 		
j['idemo010']['chunkwait'] = 0 	
j['idemo010']['cmd']['1'] = 'idemo021' 	
j['idemo010']['cmd']['2'] = 'idemo022'

j['idemo021']['fn'] = 'idemo.021' 	
j['idemo021']['auto'] = 'Y' 		
j['idemo021']['goto'] = '1' 		
j['idemo021']['renderwait'] = 4
j['idemo021']['inputwait'] = 0 		
j['idemo021']['chunksize'] = 0 		
j['idemo021']['chunkwait'] = 0 	
j['idemo021']['cmd']['1'] = 'idemo023'

j['idemo022']['fn'] = 'idemo.022' 	
j['idemo022']['auto'] = 'Y' 		
j['idemo022']['goto'] = '1' 		
j['idemo022']['renderwait'] = 6
j['idemo022']['inputwait'] = 0 		
j['idemo022']['chunksize'] = 0 		
j['idemo022']['chunkwait'] = 0 	
j['idemo022']['cmd']['1'] = 'idemo010'

j['idemo023']['fn'] = 'idemo.023' 	
j['idemo023']['auto'] = 'Y' 		
j['idemo023']['goto'] = '1' 		
j['idemo023']['renderwait'] = 5
j['idemo023']['inputwait'] = 0 		
j['idemo023']['chunksize'] = 78 		
j['idemo023']['chunkwait'] = 6 	
j['idemo023']['cmd']['1'] = 'idemo024'

j['idemo024']['fn'] = 'idemo.024' 	
j['idemo024']['auto'] = 'M' 		
j['idemo024']['goto'] = '2' 		
j['idemo024']['renderwait'] = 1
j['idemo024']['inputwait'] = 10 		
j['idemo024']['chunksize'] = 0 		
j['idemo024']['chunkwait'] = 0 	
j['idemo024']['cmd']['1'] = 'idemo025'
j['idemo024']['cmd']['2'] = 'boom'

j['idemo025']['fn'] = 'idemo.025' 	
j['idemo025']['auto'] = 'Y' 		
j['idemo025']['goto'] = '1' 		
j['idemo025']['renderwait'] = 5
j['idemo025']['inputwait'] = 0 		
j['idemo025']['chunksize'] = 0 		
j['idemo025']['chunkwait'] = 0 	
j['idemo025']['cmd']['1'] = 'idemo030'

j['boom']['fn'] = 'boom.nap' 	
j['boom']['auto'] = 'Y' 		
j['boom']['goto'] = '1' 		
j['boom']['renderwait'] = 15
j['boom']['inputwait'] = 0		
j['boom']['chunksize'] = 0 		
j['boom']['chunkwait'] = 0 	
j['boom']['cmd']['1'] = 'idemo030'

j['idemo030']['fn'] = 'idemo.030' 	
j['idemo030']['auto'] = 'N' 		
j['idemo030']['goto'] = '1' 		
j['idemo030']['renderwait'] = 6
j['idemo030']['inputwait'] = 0
j['idemo030']['chunksize'] = 0 		
j['idemo030']['chunkwait'] = 0 	
j['idemo030']['cmd']['1'] = 'idemo041'
j['idemo030']['cmd']['2'] = 'idemo042'
j['idemo030']['cmd']['3'] = 'idemo043'

j['idemo041']['fn'] = 'idemo.041' 	
j['idemo041']['auto'] = 'Y' 		
j['idemo041']['goto'] = '1' 		
j['idemo041']['renderwait'] = 4
j['idemo041']['inputwait'] = 0 		
j['idemo041']['chunksize'] = 0 		
j['idemo041']['chunkwait'] = 0 	
j['idemo041']['cmd']['1'] = 'idemo030'

j['idemo042']['fn'] = 'idemo.042' 	
j['idemo042']['auto'] = 'Y' 		
j['idemo042']['goto'] = '1' 		
j['idemo042']['renderwait'] = 4
j['idemo042']['inputwait'] = 0
j['idemo042']['chunksize'] = 0 		
j['idemo042']['chunkwait'] = 0 	
j['idemo042']['cmd']['1'] = 'idemo050'

j['idemo043']['fn'] = 'idemo.043' 	
j['idemo043']['auto'] = 'N' 		
j['idemo043']['goto'] = '1' 		
j['idemo043']['renderwait'] = 6
j['idemo043']['inputwait'] = 0 		
j['idemo043']['chunksize'] = 0 		
j['idemo043']['chunkwait'] = 0 	
j['idemo043']['cmd']['1'] = 'idemo010'
j['idemo043']['cmd']['2'] = 'idemo050'

j['idemo050']['fn'] = 'idemo.050' 	
j['idemo050']['auto'] = 'N' 		
j['idemo050']['goto'] = '1' 		
j['idemo050']['renderwait'] = 6
j['idemo050']['inputwait'] = 0
j['idemo050']['chunksize'] = 0 		
j['idemo050']['chunkwait'] = 0 	
j['idemo050']['cmd']['1'] = 'idemo010'


### Serial Connection Settings ###
ser = serial.Serial()
ser.port = "/dev/tnt1"
ser.baudrate = 1200
ser.bytesize = serial.EIGHTBITS #number of bits per bytes
ser.parity = serial.PARITY_NONE #set parity check: no parity
ser.stopbits = serial.STOPBITS_ONE #number of stop bits
ser.xonxoff = None     #software flow control
ser.rtscts = None     #hardware (RTS/CTS) flow control
ser.dsrdtr = None       #hardware (DSR/DTR) flow control
ser.timeout = 0      #read timeout, non-blocking mode
ser.writeTimeout = 1000     #timeout for write - needs a nice long one


### Send File Function ###
def sendFile (ser,fname, renderwait, chunk, chunkwait):
    if ser.isOpen():
	ser.flushInput() 
	f = open(fname, "rb")
	try:
 	    byte = f.read(1)
	    bytecount = 1
	    while byte != "":
		ser.write(byte)
		bytecount += 1
		if bytecount == chunk:
		    print "Sent " + str(chunk) + " bytes"
		    print "Pausing " + str(chunkwait) + " seconds"
		    time.sleep(chunkwait)
                    bytecount = 1
		byte = f.read(1)
	finally:
	    ser.write(byte)
	    f.close()
	    print "End of File"
	    print "Waiting " + str(renderwait) + " seconds for render"
	    time.sleep(renderwait)
            
    return
	  



### Listen Function (Listen for commands)###
def listen (ser,cmds):
    print "listening ... "
    keepgoing = 1
    while keepgoing:
	for cmd in ser.read():
	    print "got " + str(cmd)
	    if (cmd in cmds) or (cmd == "*") or (cmd == "q"):
		print "Recieved: " + str(cmd)
		keepgoing = 0
	        
    return cmd

### Listen for a while (like above, but with timeout) ###
def listen_awhile(ser,cmds,goto,q1):
    print "listening for a while ..."

    while q1.qsize() < 1:
        for cmd in ser.read():
            print "got " + str(cmd)
            if (cmd in cmds) or (cmd == "*") or (cmd == "q"):
                print "Recieved: " + str(cmd)
                q1.put("hello") #ends while loop
                print "returning input " + str(cmd)
                return cmd
            
    print "returning default " + str(goto)
    return goto


### Timeout function ###

def timeout(q1,t1):
    time.sleep(t1)
    q1.put('timedout')
    print "Timed out"


### Open Serial Connection ###
print "Initiating ..."
print "Opening serial connection ..."

try: 
    ser.open()
except Exception, e:
    print "error open serial port: " + str(e)
    exit()
    
print "Connection opened"
print "Waiting for client connection"


### Parse commands & dictionary and figure out what to do next ###
while True:

    cmds = list(j[str(next)]['cmd'].keys())
    print " "
    print "Commands: " + str(cmds)
    
    auto = j[str(next)]['auto']
    inputwait = j[str(next)]['inputwait']
    goto = j[str(next)]['goto']

    
    #if we want to automatically advance to the next frame
    if auto == "M": #auto = maybe [if no input received in time]

        #so we need a timer, ie the timeout function above
        q1 = Queue(maxsize = 0)

        worker1 = Thread(target=timeout, args=(q1,inputwait))
        worker1.setDaemon(True)
        worker1.start()

        #returns either user input cmd or goto [default] if it times out
        cmd = listen_awhile(ser,cmds,goto,q1)

    elif auto == "Y": #just go automatically, don't wait for input
	    cmd = goto

    #otherwise listen for user input to determine where to go next
    else:
	cmd = listen(ser,cmds)
        
    # "*" starts the presentation
    if cmd == "*":
	next = 'idemo010' #first frame
    elif cmd == "q":
	print "Shutting down now ..."
	exit()
    else:
	next = j[str(next)]['cmd'][cmd]

    # sendFile needs to know some things 
    renderwait = j[str(next)]['renderwait']
    chunk = j[str(next)]['chunksize']
    chunkwait = j[str(next)]['chunkwait']
    
    fname = j[str(next)]['fn']
    
    print "Initiating send with " + cmd
    print "Sending " + str(fname)
    sendFile(ser, fname, renderwait, chunk, chunkwait)
