# ChatStorage GDExtension

C++ GDExtension binding layer for the ChatStorage core library, enabling integration with Godot 4.x.

---

## Overview

This repository contains the Godot GDExtension layer for the ChatStorage ecosystem.

It acts as a bridge between:

- ChatStorage (C++ core library)
- Godot Engine 4.x

It does not contain application logic or UI. It only provides bindings and engine integration.

---

## Repository Structure

src/                 C++ GDExtension wrapper code  
godot-cpp/          Godot C++ bindings (submodule)  
bin/                Build output (not committed)  
doc_classes/        Godot class documentation bindings  
SConstruct          Build system (SCons)  
README.md

---

## Requirements

- Godot 4.x
- Python + SCons
- C++ compiler (clang/gcc/msvc depending on platform)

---

## Setup

### 1. Clone repository

git clone --recurse-submodules https://github.com/andreas-volz/chatstorage-gdextension.git  
cd chatstorage-gdextension

If already cloned:

git submodule update --init --recursive

---

### 2. Build

scons

Build outputs will be placed in:

bin/<platform>/

---

## Godot Integration

The compiled library is loaded via a `.gdextension` file inside the Godot project.

This repository does NOT contain the Godot application itself.

The Godot project using this extension has to be located in:

../chatstorage-godot/

---

## Dependency: ChatStorage Core

This extension depends on the ChatStorage core library:

https://github.com/andreas-volz/chatstorage

Make sure the core library is built and accessible during compilation.

---

## Development Notes

### Submodule

This project uses godot-cpp as a submodule:

git submodule update --init --recursive

Pinned to a stable Godot 4.x-compatible branch.

---

### Build Artifacts

The following directories are intentionally ignored:

- bin/
- build/
- Debug/
- Release/



