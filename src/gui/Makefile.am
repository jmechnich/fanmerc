bin_PROGRAMS = fanmerc_qt

nobase_dist_pkgdata_DATA = $(srcdir)/images/* $(srcdir)/sounds/*

fanmerc_qt_CPPFLAGS = -I$(top_srcdir)/src/fanmerc $(QtGui_CFLAGS)
#fanmerc_qt_CPPFLAGS += -DQT_NO_DEBUG_OUTPUT 
fanmerc_qt_CXXFLAGS = -Wall -g
fanmerc_qt_LDFLAGS = $(QtGui_LIBS)
fanmerc_qt_LDADD   = ../fanmerc/libfanmerc.a

fanmerc_qt_SOURCES = \
	fanmerc_qt.cc \
	Buttons.cc \
	HouseWindow.cc \
	LoadGameWindow.cc \
	MainMenuWindow.cc \
	MainWidget.cc \
	NodeChooseCharDetails.cc \
	NodeCreateChar.cc \
	NodeWindow.cc \
	StatusBar.cc \
	TownWindow.cc \
	Util.cc \
	$(MOC_GEN_SOURCES)

include_HEADERS = \
	Buttons.hh \
	HouseWindow.hh \
	LoadGameWindow.hh \
	MainMenuWindow.hh \
	MainWidget.hh \
	NodeChooseCharDetails.hh \
	NodeCreateChar.hh \
	NodeWindow.hh \
	PointerMap.hh \
	PointerMap.icc \
	StatusBar.hh \
	StatusBar.icc \
	TownWindow.hh \
	Util.hh

MOC_GEN_SOURCES = \
	moc_Buttons.cc \
	moc_MainWidget.cc \
	moc_NodeCreateChar.cc \
	moc_NodeWindow.cc \
	moc_TownWindow.cc

#  Rules for moc
#
$(MOC_GEN_SOURCES): moc_%.cc: %.hh
	$(MOC) $< -o $@

MOSTLYCLEANFILES = $(MOC_GEN_SOURCES)
