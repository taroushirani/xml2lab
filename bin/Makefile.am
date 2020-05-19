AUTOMAKE_OPTIONS = subdir-objects

AM_CPPFLAGS = -I @top_srcdir@/sinsy/include -I @top_srcdir@/sinsy/lib -I @top_srcdir@/sinsy/lib/converter -I @top_srcdir@/sinsy/lib/hts_engine_API -I @top_srcdir@/sinsy/lib/japanese -I @top_srcdir@/sinsy/lib/label -I @top_srcdir@/sinsy/lib/score -I @top_srcdir@/sinsy/lib/temporary -I @top_srcdir@/sinsy/lib/util -I @top_srcdir@/sinsy/lib/xml

bin_PROGRAMS = xml2lab

xml2lab_SOURCES = xml2lab.cpp \
		../sinsy/lib/converter/ConfGroup.cpp \
		../sinsy/lib/converter/ConfGroup.h \
		../sinsy/lib/converter/ConfManager.cpp \
		../sinsy/lib/converter/ConfManager.h \
		../sinsy/lib/converter/Converter.cpp \
		../sinsy/lib/converter/Converter.h \
		../sinsy/lib/converter/IConf.h \
		../sinsy/lib/converter/IConvertable.h \
		../sinsy/lib/converter/PhonemeInfo.cpp \
		../sinsy/lib/converter/PhonemeInfo.h \
		../sinsy/lib/converter/UnknownConf.cpp \
		../sinsy/lib/converter/UnknownConf.h \
		../sinsy/lib/converter/util_converter.cpp \
		../sinsy/lib/converter/util_converter.h \
		../sinsy/lib/hts_engine_API/SynthConditionImpl.cpp \
		../sinsy/lib/hts_engine_API/SynthConditionImpl.h \
		../sinsy/lib/japanese/JConf.cpp \
		../sinsy/lib/japanese/JConf.h \
		../sinsy/lib/label/ILabelOutput.h \
		../sinsy/lib/label/INoteLabel.h \
		../sinsy/lib/label/IPhonemeLabel.h \
		../sinsy/lib/label/ISyllableLabel.h \
		../sinsy/lib/label/LabelData.cpp \
		../sinsy/lib/label/LabelData.h \
		../sinsy/lib/label/LabelMaker.cpp \
		../sinsy/lib/label/LabelMaker.h \
		../sinsy/lib/label/LabelMeasure.cpp \
		../sinsy/lib/label/LabelMeasure.h \
		../sinsy/lib/label/LabelPosition.cpp \
		../sinsy/lib/label/LabelPosition.h \
		../sinsy/lib/label/LabelStream.cpp \
		../sinsy/lib/label/LabelStream.h \
		../sinsy/lib/label/LabelStrings.cpp \
		../sinsy/lib/label/LabelStrings.h \
		../sinsy/lib/label/NoteGroup.cpp \
		../sinsy/lib/label/NoteGroup.h \
		../sinsy/lib/label/NoteLabeler.cpp \
		../sinsy/lib/label/NoteLabeler.h \
		../sinsy/lib/label/PhonemeLabeler.cpp \
		../sinsy/lib/label/PhonemeLabeler.h \
		../sinsy/lib/label/SyllableLabeler.cpp \
		../sinsy/lib/label/SyllableLabeler.h \
		../sinsy/lib/score/Beat.cpp \
		../sinsy/lib/score/Beat.h \
		../sinsy/lib/score/Dynamics.cpp \
		../sinsy/lib/score/Dynamics.h \
		../sinsy/lib/score/IScoreWritable.h \
		../sinsy/lib/score/IScoreWriter.h \
		../sinsy/lib/score/Key.cpp \
		../sinsy/lib/score/Key.h \
		../sinsy/lib/score/Mode.cpp \
		../sinsy/lib/score/Mode.h \
		../sinsy/lib/score/Note.cpp \
		../sinsy/lib/score/Note.h \
		../sinsy/lib/score/Pitch.cpp \
		../sinsy/lib/score/Pitch.h \
		../sinsy/lib/score/ScorePosition.cpp \
		../sinsy/lib/score/ScorePosition.h \
		../sinsy/lib/score/Slur.cpp \
		../sinsy/lib/score/Slur.h \
		../sinsy/lib/score/Syllabic.cpp \
		../sinsy/lib/score/Syllabic.h \
		../sinsy/lib/score/util_score.cpp \
		../sinsy/lib/score/util_score.h \
		../sinsy/lib/temporary/ScoreDoctor.cpp \
		../sinsy/lib/temporary/ScoreDoctor.h \
		../sinsy/lib/temporary/TempScore.cpp \
		../sinsy/lib/temporary/TempScore.h \
		../sinsy/lib/util/Configurations.cpp \
		../sinsy/lib/util/Configurations.h \
		../sinsy/lib/util/Deleter.h \
		../sinsy/lib/util/DiphthongConverter.cpp \
		../sinsy/lib/util/DiphthongConverter.h \
		../sinsy/lib/util/ForEachAdapter.h \
		../sinsy/lib/util/IReadableStream.h \
		../sinsy/lib/util/IStringable.cpp \
		../sinsy/lib/util/IStringable.h \
		../sinsy/lib/util/IWritableStream.h \
		../sinsy/lib/util/InputFile.cpp \
		../sinsy/lib/util/InputFile.h \
		../sinsy/lib/util/MacronTable.cpp \
		../sinsy/lib/util/MacronTable.h \
		../sinsy/lib/util/MultibyteCharRange.cpp \
		../sinsy/lib/util/MultibyteCharRange.h \
		../sinsy/lib/util/OutputFile.cpp \
		../sinsy/lib/util/OutputFile.h \
		../sinsy/lib/util/PhonemeTable.cpp \
		../sinsy/lib/util/PhonemeTable.h \
		../sinsy/lib/util/StreamException.h \
		../sinsy/lib/util/StringTokenizer.cpp \
		../sinsy/lib/util/StringTokenizer.h \
		../sinsy/lib/util/WritableStrStream.h \
		../sinsy/lib/util/util_log.h \
		../sinsy/lib/util/util_string.cpp \
		../sinsy/lib/util/util_string.h \
		../sinsy/lib/util/util_types.h \
		../sinsy/lib/xml/XmlData.cpp \
		../sinsy/lib/xml/XmlData.h \
		../sinsy/lib/xml/XmlParser.cpp \
		../sinsy/lib/xml/XmlParser.h \
		../sinsy/lib/xml/XmlReader.cpp \
		../sinsy/lib/xml/XmlReader.h \
		../sinsy/lib/xml/XmlWriter.cpp \
		../sinsy/lib/xml/XmlWriter.h \
		../sinsy/lib/xml/xml_tags.h

DISTCLEANFILES = *.log *.out *~

MAINTAINERCLEANFILES = Makefile.in 
