Name:		ml-pnet
Summary:	Mono library for DotGNU Portable .NET
Version:	0.8.1
Release:	custom

Group:		System Environment/Base
License:	LGPL
URL:		http://www.dotgnu.org
Source:		http://www.southern-storm.com.au/download/ml-pnet-%{version}.tar.gz  
BuildRoot:	%{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

Requires:	pnet-interpreter >= 0:0.8.1
Requires:	pnet-tools >= 0:0.8.1
Requires:	pnetlib >= 0:0.8.1

BuildRequires:	pnet-compiler >= 0:0.8.1
BuildRequires:	pnet-tools >= 0:0.8.1
BuildRequires:	pnet-interpreter >= 0:0.8.1
BuildRequires:	pnetlib >= 0:0.8.1

BuildArch:	noarch

%description
The package contains some of the Mono CLR Libraries
recompiled for DotGNU's Portable .NET runtime.

%prep
%setup -q -n ml-pnet-%{version}

%build
%configure
make %{?_smp_mflags}

%install
test "${RPM_BUILD_ROOT}" = "/" || rm -rf ${RPM_BUILD_ROOT}
make install DESTDIR=${RPM_BUILD_ROOT}

%clean
test "${RPM_BUILD_ROOT}" = "/" || rm -rf ${RPM_BUILD_ROOT}

%files
%defattr(-,root,root,-)
%doc AUTHORS COPYING NEWS README INSTALL
%{_libdir}/cscc/lib

%changelog
* Thu Sep 08 2004 Russell Stuart <rstuart-rpm@stuart.id.au>
- Epoc
