#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "CutAdaptPlugin.h"

void CutAdaptPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}

void CutAdaptPlugin::run() {
   
}

void CutAdaptPlugin::output(std::string file) {
	//cutadapt S12_R1.fastq -a CNCCACTCT -o S12_R1.trimmed.fastq
	std::string command = "cutadapt "+std::string(PluginManager::prefix())+"/"+parameters["fastqfile"];
 command += " -a "+parameters["adapter"];
 command += " -o "+file;
 std::cout << command << std::endl;
 system(command.c_str());
}

PluginProxy<CutAdaptPlugin> CutAdaptPluginProxy = PluginProxy<CutAdaptPlugin>("CutAdapt", PluginManager::getInstance());
