thisdir = class/System.Data
SUBDIRS = 
include ../../build/rules.make

# I have *no idea* why I need to do this.

ifeq ($(PROFILE),atomic)
system = System.dll
else
system = $(topdir)/class/lib/$(PROFILE)/System.dll
endif

LIBRARY = System.Data.dll
LIB_MCS_FLAGS = \
	/nowarn:649 /nowarn:169 /nowarn:219 /nowarn:168 /nowarn:1595 \
	/r:$(corlib)				\
	/r:$(system)			 	\
	/r:System.Xml.dll 			\
	/r:System.EnterpriseServices.dll 	\
	/r:Mono.Data.Tds.dll

TEST_MCS_FLAGS = $(LIB_MCS_FLAGS) /nowarn:618

EXTRA_DISTFILES = \
	TODO					\
	Test/System.Data/region.xml		\
	Test/System.Data/store.xsd		\
	Test/System.Data/own_schema.xsd		\
	Test/System.Xml/2books.xml		\
	Test/System.Xml/region.xml		\
	Test/System.Xml/region.xsd		\
	Test/System.Xml/store.xsd		\
	Mono.Data.SqlExpressions/Parser.jay	\
	app_test_2.0.config

BUILT_SOURCES = Mono.Data.SqlExpressions/Parser.cs

Mono.Data.SqlExpressions/Parser.cs: Mono.Data.SqlExpressions/Parser.jay $(topdir)/jay/skeleton.cs
	$(topdir)/jay/jay -ct < $(topdir)/jay/skeleton.cs $< >$@

include ../../build/library.make

ifeq (net_2_0, $(PROFILE))
$(test_lib): $(test_lib).config

$(test_lib).config: app_test_2.0.config
	cp $< $@
endif

