# vm download: https://drive.google.com/file/d/0B3np0Se6U29KUVNhUlk5cHVhLTg/view?usp=sharing

# user: vmware
# pass: vmware

# to check the ip: ifconfig

# to start the server: java -jar Javatopia3-0.1.1-SNAPSHOT.jar

# to browse: http://<ip>:8080/


import urllib2


HOST_URL="http://172.16.18.240:8080"
OBJECTS_API = "/api/sector/%d/objects"
ROOTS_API = "/api/sector/%d/roots"



def get_objects(sector):
	url = HOST_URL + OBJECTS_API % sector
	print
	print url

	res=urllib2.urlopen(url)
	edges = []
	for line in res.readlines():
		edges.append( [int(s) for s in line.strip().split(' ')] )
	return edges
	

def get_roots(sector):
	url = HOST_URL + ROOTS_API % sector
	print
	print url

	res=urllib2.urlopen(url)
	nodes = []
	for line in res.readlines():
		nodes.append(int(line.strip()))
	
	return nodes
	



edges = get_objects(1)
print edges


edges = get_objects(2)
print edges


roots = get_roots(1)
print roots

