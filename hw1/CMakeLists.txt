cmake_minimum_required(VERSION 3.17)
project(hw1)

set(CMAKE_CXX_STANDARD 14)
#add_compile_definitions(ANDROID)
add_compile_definitions(HARMONYOS)
#add_compile_definitions(IOS)

add_executable(
        hw1
        main.cpp
        AlertDialogFormBuilder.cpp
        AlertDialogFormBuilder.h
        AndroidDialogFormImpl.cpp
        AndroidDialogFormImpl.h
        Director.cpp
        Director.h
        DialogFormImpl.cpp
        DialogFormImpl.h
        DialogFormBuilder.cpp
        DialogFormBuilder.h
        IOSDialogFormImpl.cpp
        IOSDialogFormImpl.h
        NavbarDialogFormBuilder.cpp
        NavbarDialogFormBuilder.h
        OverscreenDialogFormBuilder.cpp
        OverscreenDialogFormBuilder.h
        StyleSheetDefinition.h
        HarmonyOSDialogFormImpl.cpp
        HarmonyOSDialogFormImpl.h
        DialogForm.cpp DialogForm.h)