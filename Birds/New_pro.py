#!/usr/bin/python

import os
import sys
import shutil
import errno


def print_usage(arg):
    print sys.argv[0] + " usage: --yes for auto yes"
    print "--help for print this message"

def cp_file(src, dst):
    print "copy : " + src;
    try:
        shutil.copy(src, dst);
    except IOError, e:
        print "Error " + e.filename + ": " + e.strerror

def cp_dir(src, dst):
    print "copy : " + src;
    try:
        shutil.copytree(src, dst);
    except IOError, e:
        print "Error " + e.filename + ": " + e.strerror

def mkdir(path):
    print "Creation de : " + path
    try:
        os.mkdir(path, 0755);
    except OSError, e:
        print "Error " + e.filename + ": " + e.strerror
        if e.errno == errno.EEXIST:
            ret = raw_input('Do you whant continue ?[Y/n]\n')
            if ret == "Y" or ret == "y" or ret == "":
                return 
        sys.exit(-1)


def mkfile(string, path):
    print "Creation : " + path
    try:
        fd = open(path, "a");
        fd.write(string);
        fd.close();
    except IOError, e:
        print "Error " + e.filename + ": " + e.strerror


class Template_crea:

    def __init__(self, name, path):
        self.name = name;
        self.path = path;

    def run_crea(self):
        mkdir(self.path + self.name);

class Template_cp:

    def __init__(self, name, src_path, dst_path):
        self.name = name;
        self.src_path = src_path;
        self.dst_path = dst_path;

    def run_file(self):
        cp_file(self.src_path, self.dst_path);

class Project:

    def __init__(self, name, language):
        self.name = name;
        self.language = language;
        self.in_path = os.getcwd() + "/" + name + "/"
        self.template_crea = [];
        self.template_cp = [];

    def Addtemplate_crea(self, tab):
        self.template_crea.append(Template_crea(tab['name'], tab['path']));

    def Addtemplate_cp(self, tab):
        self.template_cp.append(Template_cp(tab['name'], tab['src_path'], tab['dst_path']));

    def run_crea(self):
        for temp in self.template_crea:
            temp.run_crea();

    def run_cp(self):
        for temp in self.template_cp:
            temp.run_file();


#def parseur(argv):
#    for arg in argv:
#        if arg == "--yes":
#            g_auto_yes = True;
#            print g_auto_yes
#        elif arg == "--help":
#           print_usage();
#           sys.exit(1);
#        else:
#            print_usage();


def default_crea_c(pro):
    pwd = os.getcwd();
    pro.Addtemplate_crea({ 'name' : "srcs", 'path' : pro.in_path });
    pro.Addtemplate_crea({ 'name' : "include", 'path' : pro.in_path});
    pro.Addtemplate_crea({ 'name' : ".conf.mk", 'path' : pro.in_path});

def default_cp_c(pro):
    pwd = os.getcwd();
    deflaut_path = pwd + "/template/"
    pro.Addtemplate_cp({ 'name' : ".gitignore",
        'src_path' : deflaut_path + "gitignore",
        'dst_path' : pro.in_path + ".gitignore"});
    pro.Addtemplate_cp({ 'name' : "Makefile",
        'src_path' : deflaut_path + "root.mk",
        'dst_path' : pro.in_path + "Makefile"});

def c_thing(pro):
    default_crea_c(pro);
    default_cp_c(pro);
    pro.run_crea();
    cp_dir(os.getcwd() + "/template/libft", pro.in_path + "libft")
    pro.run_cp();



def cpp():
    print "cpp je c'est pas fair encor"

support_lang = [
        { 'name' : "C", 'fonction' : c_thing },
        { 'name' : "C++", 'fonction' : cpp }]

def main():
    #parseur(sys.argv[1:])
    name = raw_input('Projet name: ');
    lang = raw_input('Language: ');
    name = name.strip();
    lang = lang.strip();
    pro = Project(name, lang);
    mkdir(name);
    mkfile(os.environ["LOGNAME"], pro.in_path + "auteur");
    for case in support_lang:
        if case['name'] == lang:
            case['fonction'](pro);
            break;

if __name__ == "__main__":
    main();

