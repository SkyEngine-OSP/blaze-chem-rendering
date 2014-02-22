#!/bin/sh

echo 'What up dawg ... ';

echo 'gonna help with ur install of ogre and avogadro';

echo 'Going to start with ogre, but have to get some libraries first.';

export THE_ROOT_DIR=${PWD};
export SRC_DIRS=${THE_ROOT_DIR}/source_tars;

sudo apt-get install build-essential automake libtool libfreetype6-dev libfreeimage-dev libzzip-dev libxrandr-dev libxaw7-dev freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev libxt-dev libpng3-dev nvidia-cg-toolkit libois-dev libboost-thread-dev doxygen graphviz libcppunit-dev;

echo 'now ... for avogadro.'

sudo apt-get install python python-dev; 
sudo apt-get install libavogadro-dev;

echo 'And last but CERTAINLY not least...';

sudo apt-get install cmake wget;

echo 'Finally, we get to ogre';
echo '(just because im anal, were gonna do a final pass over ogre required deps...)'

sudo apt-get install libogre-dev;

echo 'now for some fun...';
#uncomment line below if you want to download from the web
#wget http://downloads.sourceforge.net/project/ogre/ogre/1.8/1.8.1/ogre_src_v1-8-1.tar.bz2?r=http%3A%2F%2Fwww.ogre3d.org%2Fdownload%2Fsource&ts=1391731839&use_mirror=iweb;


mkdir scripts && mkdir libs && mkdir ogre && mkdir avogadro;
export SCRIPTS_DIR=${THE_ROOT_DIR}/scripts;
export LIBS_DIR=${THE_ROOT_DIR}/libs;
export OGRE_DIR=${THE_ROOT_DIR}/ogre;
export AVO_DIR=${THE_ROOT_DIR}/avogadro;

#start with SIP python jazz
cp ${SRC_DIRS}/sip-4.15.4.tar.gz ${LIBS_DIR}; 
cd ${LIBS_DIR} && tar xvf sip-4.15.4.tar.gz && cd sip-4.15.4;
python configure.py && make && sudo make install;
echo 'Extra lib setup done :>';


cp ${SRC_DIRS}/ogre_src_v1-8-1.tar.bz2 ${OGRE_DIR};
echo 'going to unzip ogres tar file from the parent dir into this directory';
cd ${OGRE_DIR} && tar xjf ogre_src_v1-8-1.tar.bz2;
echo 'going to make a build directory and cmake the source in it.';
cd ogre_src_v1-8-1 && mkdir build && cd build && cmake ..;
echo 'if that worked, going to build the program now.';
make && sudo make install;
echo 'Ogre done :>';
cd bin;
echo 'cd '$PWD && echo ' && ./SampleBrowser' >> ${SCRIPTS_DIR}'/ogre.sh' && chmod u+x ${SCRIPTS_DIR}'/ogre.sh';

cp ${SRC_DIRS}/avogadro-1.1.1.tar.bz2 ${AVO_DIR};
cd ${AVO_DIR} && tar xjf avogadro-1.1.1.tar.bz2 && cd avogadro-1.1.1;
mkdir build && cd build && cmake .. && make && sudo make install;
cd bin;
echo 'cd '$PWD && echo ' && ./avogadro' >> ${SCRIPTS_DIR}'/avogadro.sh' && chmod u+x ${SCRIPTS_DIR}'/avogadro.sh';
echo 'avogadro done :>';

cd ${SCRIPTS_DIR} && echo 'what up yo';

