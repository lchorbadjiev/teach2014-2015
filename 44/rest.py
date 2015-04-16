import urllib2



SERVER_HOST="http://172.16.18.240:8080"

OBJECTS_API = "/api/sector/%d/objects"
ROOTS_API = "/api/sector/%d/roots"


def get_objects(sector):
	url=SERVER_HOST+OBJECTS_API%sector
	print url
	res=urllib2.urlopen(url)
	edges = []
	for line in res.readlines():
		line=line.strip().split(' ')
		nodes=[int(s) for s in line]
		# print nodes
		edges.append(nodes)
	return edges

def get_roots(sector):
	url=SERVER_HOST+ROOTS_API%sector
	print url
	res=urllib2.urlopen(url)
	nodes = []
	for line in res.readlines():
		node=int(line.strip())
		nodes.append(node)
	return nodes



edges = get_objects(2)		
print edges

edges = get_objects(3)		
print edges

edges = get_objects(4)		
print edges

roots = get_roots(2)
print roots

roots = get_roots(3)
print roots
	

