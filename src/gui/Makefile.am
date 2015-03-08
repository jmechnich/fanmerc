INCLUDES = -I$(top_srcdir)/src/fanmerc
MOC      = @QT_MOC@
AM_CXXFLAGS = -Wall -g @QT_CXXFLAGS@

bin_PROGRAMS = fanmerc_qt

nobase_dist_pkgdata_DATA = images/* sounds/*

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
	TownWindow.cc

fanmerc_qt_LDADD    = $(top_builddir)/src/fanmerc/libfanmerc.a @QT_LIBS@

MOC_GEN_SOURCES = \
	moc_Buttons.cc \
	moc_MainWidget.cc \
	moc_NodeCreateChar.cc \
	moc_NodeWindow.cc \
	moc_TownWindow.cc

nodist_fanmerc_qt_SOURCES = $(MOC_GEN_SOURCES)

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
	TownWindow.hh

moc_%.cc: %.hh
	$(MOC) $< -o $@

MOSTLYCLEANFILES = $(MOC_GEN_SOURCES)
