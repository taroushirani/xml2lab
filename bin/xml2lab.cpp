//
// xml2lab: convert MusicXML file to fullcontext HTS label for singing voice synthesis.
// This program uses many codes from sinsy, the HMM-based singing voice synthesis system.
// 

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>

#include "sinsy/lib/converter/Converter.h"
#include "sinsy/lib/label/LabelMaker.h"
#include "sinsy/lib/label/LabelStrings.h"
#include "sinsy/lib/score/util_score.h"
#include "sinsy/lib/temporary/ScoreDoctor.h"
#include "sinsy/lib/util/InputFile.h"
#include "sinsy/lib/util/OutputFile.h"
#include "sinsy/lib/xml/XmlReader.h"

namespace
{
const char* DEFAULT_LANGS = "j";
};

void usage()
{
    std::cout << "xml2lab: Convert MusicXML to full-context HTS label."<< std::endl;
    std::cout << "This program uses many codes from sinsy, The HMM-Based " << std::endl;
    std::cout << "Singing Voice Synthesis System." << std::endl;
    std::cout << "Original copyright notices are as follows:" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "The HMM-Based Singing Voice Syntheis System \"Sinsy\"" << std::endl;
    std::cout << "Version 0.92 (http://sinsy.sourceforge.net/)" << std::endl;
    std::cout << "Copyright (C) 2009-2015 Nagoya Institute of Technology" << std::endl;
    std::cout << "All rights reserved." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "  usage:" << std::endl;
    std::cout << "    xml2lab [ options ] [ infile ]" << std::endl;
    std::cout << "  options:                                           [default]" << std::endl;
    std::cout << "    -w langs    : languages                          [   j   ]" << std::endl;
    std::cout << "                  j: Japanese                                 " << std::endl;
    std::cout << "                  (Currently, you can set only Japanese)      " << std::endl;
    std::cout << "    -x dir      : dictionary directory               [  N/A  ]" << std::endl;
    std::cout << "    -m          : output monophone label             [ false ]" << std::endl;
    std::cout << "    -t          : time format of output label(0,1,2) [   1   ]" << std::endl;
    std::cout << "    -o file     : filename of output lab file        [  N/A  ]" << std::endl;
    std::cout << "  infile:" << std::endl;
    std::cout << "    MusicXML file" << std::endl;

}

int main(int argc, char **argv)
{
    if (argc < 2) {
	usage();
	std::exit(EXIT_FAILURE);
    }

    std::string xml;
    std::string config;
    std::string lab;
    std::string timeFlagStr;
    std::string languages(DEFAULT_LANGS);
    bool monophoneFlag(false);
    int timeFlag(1);
    
    int i(1);
    for(; i< argc; i++){
	if ('-' != argv[i][0]) {
	    if (xml.empty()) {
		xml = argv[i];
	    } else {
		std::cerr << "[ERROR] Invalid option : '" << argv[i][1] << "'" << std::endl;
		usage();
		std::exit(EXIT_FAILURE);
	    }
	} else {
	    switch (argv[i][1]) {
	    case 'w' :
		languages = argv[++i];
		break;
	    case 'x' :
		config = argv[++i];
		break;
	    case 'o' :
		lab = argv[++i];
		break;
	    case 'm' :
		monophoneFlag = true;
		break;
	    case 't' :
		timeFlagStr = argv[++i];
		if (timeFlagStr.size() == 0) {
		    std::cerr << "[ERROR] Must specify time format" << std::endl;
		    usage();
		    std::exit(EXIT_FAILURE);
		} else {
		    timeFlag = atoi(timeFlagStr.c_str());
		    break;
		}
	    case 'h' :
		usage();
		std::exit(EXIT_SUCCESS);
	    default :
		std::cerr << "[ERROR] Invalid option : '-" << argv[i][1] << "'" << std::endl;
		usage();
		std::exit(EXIT_FAILURE);
		
	    }
	}
    }

    if(xml.empty()) {
	usage();
	return -1;
    }

    sinsy::Converter converter;
    if(!converter.setLanguages(languages, config)) {
	std::cerr << "[ERROR] Failed to set languages : " << languages << ", config dir : " << config << std::endl;
	std::exit(EXIT_FAILURE);
    }

    sinsy::InputFile xmlFile(xml);
    if(!xmlFile.isValid()) {
	std::cerr << "[ERROR] Failed to open Xml file : " << xml << std::endl;
	std::exit(EXIT_FAILURE);
    }
    
    sinsy::XmlReader xmlReader;
    if (!xmlReader.readXml(xmlFile)) {
	std::cerr << "[ERROR] Failed to parse Xml file : " << xml << std::endl;
	std::exit(EXIT_FAILURE);
    }
#ifdef DEBUG
    xmlReader.getXmlData()->toStringStream(std::cout);
#endif
    sinsy::ScoreDoctor score;
    score << xmlReader;
    
    sinsy::LabelMaker labelMaker(converter);
    labelMaker << score;
    labelMaker.fix();

    sinsy::LabelStrings label;
    labelMaker.outputLabel(label, monophoneFlag, 1, timeFlag);

    std::ostringstream oss;

    int j(0);
    const char* const * label_str_array = label.getData();
    for (; j < label.size(); j++) {
	oss << label_str_array[j] << std::endl;
    }
    
    if (lab.empty()) {
	std::cout << oss.str() << std::endl;
    } else {
	sinsy::OutputFile labFile(lab);
	if(!labFile.isValid()) {
	    std::cerr << "[ERROR] Failed to open Output file : " << lab << std::endl;
	    std::exit(EXIT_FAILURE);
	}
	labFile.write(oss.str().c_str(), oss.str().size());
    }

    std::exit(EXIT_SUCCESS);
}
