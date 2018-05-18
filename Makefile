bin_path="/usr/local/bin"
pname="cftool"
ver="0.11"

all:
	

install:
	ln -f ${pname}-${ver} ${bin_path}/${pname}
	
