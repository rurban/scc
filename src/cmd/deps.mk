#deps
./addr2line.o: $(INCDIR)/scc/scc/arg.h
./addr2line.o: $(INCDIR)/scc/scc/mach.h
./ar.o: $(INCDIR)/scc/scc/ar.h
./ar.o: $(INCDIR)/scc/scc/arg.h
./ar.o: ./sys.h
./as/expr.o: $(INCDIR)/scc/scc/scc.h
./as/expr.o: ./as/as.h
./as/ins.o: $(INCDIR)/scc/scc/scc.h
./as/ins.o: ./as/as.h
./as/main.o: $(INCDIR)/scc/scc/arg.h
./as/main.o: $(INCDIR)/scc/scc/scc.h
./as/main.o: ./as/as.h
./as/parser.o: $(INCDIR)/scc/scc/cstd.h
./as/parser.o: $(INCDIR)/scc/scc/scc.h
./as/parser.o: ./as/as.h
./as/symbol.o: $(INCDIR)/scc/scc/scc.h
./as/symbol.o: ./as/as.h
./as/target/x80/ins.o: $(INCDIR)/scc/scc/scc.h
./as/target/x80/ins.o: ./as/target/x80/../../as.h
./as/target/x80/ins.o: ./as/target/x80/proc.h
./as/target/x80/z80.o: $(INCDIR)/scc/scc/scc.h
./as/target/x80/z80.o: ./as/target/x80/../../as.h
./as/target/x80/z80.o: ./as/target/x80/../x80/proc.h
./as/target/x80/z80tbl.o: $(INCDIR)/scc/scc/scc.h
./as/target/x80/z80tbl.o: ./as/target/x80/../../as.h
./as/target/x80/z80tbl.o: ./as/target/x80/../x80/proc.h
./as/target/x86/amd64.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/amd64.o: ./as/target/x86/../../as.h
./as/target/x86/amd64tbl.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/amd64tbl.o: ./as/target/x86/../../as.h
./as/target/x86/amd64tbl.o: ./as/target/x86/../x86/proc.h
./as/target/x86/i286.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/i286.o: ./as/target/x86/../../as.h
./as/target/x86/i286.o: ./as/target/x86/../x86/proc.h
./as/target/x86/i286tbl.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/i286tbl.o: ./as/target/x86/../../as.h
./as/target/x86/i286tbl.o: ./as/target/x86/../x86/proc.h
./as/target/x86/i386.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/i386.o: ./as/target/x86/../../as.h
./as/target/x86/i386.o: ./as/target/x86/../x86/proc.h
./as/target/x86/i386tbl.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/i386tbl.o: ./as/target/x86/../../as.h
./as/target/x86/i386tbl.o: ./as/target/x86/../x86/proc.h
./as/target/x86/ins.o: $(INCDIR)/scc/scc/scc.h
./as/target/x86/ins.o: ./as/target/x86/../../as.h
./as/target/x86/ins.o: ./as/target/x86/proc.h
./ld/main.o: $(INCDIR)/scc/scc/ar.h
./ld/main.o: $(INCDIR)/scc/scc/mach.h
./ld/main.o: $(INCDIR)/scc/scc/scc.h
./ld/main.o: $(INCDIR)/scc/scc/syslibs.h
./nm.o: $(INCDIR)/scc/scc/arg.h
./nm.o: $(INCDIR)/scc/scc/mach.h
./objdump.o: $(INCDIR)/scc/scc/arg.h
./objdump.o: $(INCDIR)/scc/scc/mach.h
./posix.o: ./sys.h
./ranlib.o: $(INCDIR)/scc/scc/ar.h
./ranlib.o: $(INCDIR)/scc/scc/arg.h
./ranlib.o: $(INCDIR)/scc/scc/mach.h
./ranlib.o: $(INCDIR)/scc/scc/scc.h
./ranlib.o: ./sys.h
./scc/cc1/builtin.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/builtin.o: ./scc/cc1/cc1.h
./scc/cc1/code.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/code.o: ./scc/cc1/cc1.h
./scc/cc1/cpp.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/cpp.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/cpp.o: ./scc/cc1/cc1.h
./scc/cc1/decl.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/decl.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/decl.o: ./scc/cc1/cc1.h
./scc/cc1/error.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/error.o: ./scc/cc1/cc1.h
./scc/cc1/expr.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/expr.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/expr.o: ./scc/cc1/cc1.h
./scc/cc1/fold.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/fold.o: ./scc/cc1/cc1.h
./scc/cc1/init.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/init.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/init.o: ./scc/cc1/cc1.h
./scc/cc1/lex.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/lex.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/lex.o: ./scc/cc1/cc1.h
./scc/cc1/main.o: $(INCDIR)/scc/scc/arg.h
./scc/cc1/main.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/main.o: ./scc/cc1/cc1.h
./scc/cc1/stmt.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/stmt.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/stmt.o: ./scc/cc1/cc1.h
./scc/cc1/symbol.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/symbol.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/symbol.o: ./scc/cc1/cc1.h
./scc/cc1/target/amd64-sysv/arch.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/target/amd64-sysv/arch.o: ./scc/cc1/target/amd64-sysv/../../cc1.h
./scc/cc1/target/arm64-sysv/arch.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/target/arm64-sysv/arch.o: ./scc/cc1/target/arm64-sysv/../../cc1.h
./scc/cc1/target/i386-sysv/arch.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/target/i386-sysv/arch.o: ./scc/cc1/target/i386-sysv/../../cc1.h
./scc/cc1/target/z80-scc/arch.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/target/z80-scc/arch.o: ./scc/cc1/target/z80-scc/../../cc1.h
./scc/cc1/types.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc1/types.o: $(INCDIR)/scc/scc/scc.h
./scc/cc1/types.o: ./scc/cc1/cc1.h
./scc/cc2/code.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/code.o: ./scc/cc2/cc2.h
./scc/cc2/main.o: $(INCDIR)/scc/scc/arg.h
./scc/cc2/main.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/main.o: ./scc/cc2/cc2.h
./scc/cc2/main.o: ./scc/cc2/error.h
./scc/cc2/node.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/node.o: ./scc/cc2/cc2.h
./scc/cc2/optm.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/optm.o: ./scc/cc2/cc2.h
./scc/cc2/parser.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc2/parser.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/parser.o: ./scc/cc2/cc2.h
./scc/cc2/peep.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/peep.o: ./scc/cc2/cc2.h
./scc/cc2/symbol.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/symbol.o: ./scc/cc2/cc2.h
./scc/cc2/target/amd64-sysv/cgen.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/amd64-sysv/cgen.o: ./scc/cc2/target/amd64-sysv/../../cc2.h
./scc/cc2/target/amd64-sysv/cgen.o: ./scc/cc2/target/amd64-sysv/arch.h
./scc/cc2/target/amd64-sysv/code.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc2/target/amd64-sysv/code.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/amd64-sysv/code.o: ./scc/cc2/target/amd64-sysv/../../cc2.h
./scc/cc2/target/amd64-sysv/code.o: ./scc/cc2/target/amd64-sysv/arch.h
./scc/cc2/target/amd64-sysv/optm.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/amd64-sysv/optm.o: ./scc/cc2/target/amd64-sysv/../../cc2.h
./scc/cc2/target/amd64-sysv/types.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/amd64-sysv/types.o: ./scc/cc2/target/amd64-sysv/../../cc2.h
./scc/cc2/target/i386-sysv/cgen.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/i386-sysv/cgen.o: ./scc/cc2/target/i386-sysv/../../cc2.h
./scc/cc2/target/i386-sysv/cgen.o: ./scc/cc2/target/i386-sysv/arch.h
./scc/cc2/target/i386-sysv/code.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc2/target/i386-sysv/code.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/i386-sysv/code.o: ./scc/cc2/target/i386-sysv/../../cc2.h
./scc/cc2/target/i386-sysv/code.o: ./scc/cc2/target/i386-sysv/arch.h
./scc/cc2/target/i386-sysv/optm.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/i386-sysv/optm.o: ./scc/cc2/target/i386-sysv/../../cc2.h
./scc/cc2/target/i386-sysv/types.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/i386-sysv/types.o: ./scc/cc2/target/i386-sysv/../../cc2.h
./scc/cc2/target/qbe/cgen.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc2/target/qbe/cgen.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/qbe/cgen.o: ./scc/cc2/target/qbe/../../cc2.h
./scc/cc2/target/qbe/cgen.o: ./scc/cc2/target/qbe/arch.h
./scc/cc2/target/qbe/code.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc2/target/qbe/code.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/qbe/code.o: ./scc/cc2/target/qbe/../../cc2.h
./scc/cc2/target/qbe/code.o: ./scc/cc2/target/qbe/arch.h
./scc/cc2/target/qbe/optm.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/qbe/optm.o: ./scc/cc2/target/qbe/../../cc2.h
./scc/cc2/target/z80-scc/cgen.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/z80-scc/cgen.o: ./scc/cc2/target/z80-scc/../../cc2.h
./scc/cc2/target/z80-scc/cgen.o: ./scc/cc2/target/z80-scc/arch.h
./scc/cc2/target/z80-scc/code.o: $(INCDIR)/scc/scc/cstd.h
./scc/cc2/target/z80-scc/code.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/z80-scc/code.o: ./scc/cc2/target/z80-scc/../../cc2.h
./scc/cc2/target/z80-scc/code.o: ./scc/cc2/target/z80-scc/arch.h
./scc/cc2/target/z80-scc/optm.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/z80-scc/optm.o: ./scc/cc2/target/z80-scc/../../cc2.h
./scc/cc2/target/z80-scc/types.o: $(INCDIR)/scc/scc/scc.h
./scc/cc2/target/z80-scc/types.o: ./scc/cc2/target/z80-scc/../../cc2.h
./scc/posix/scc.o: $(INCDIR)/scc/scc/arg.h
./scc/posix/scc.o: $(INCDIR)/scc/scc/ldflags.h
./scc/posix/scc.o: $(INCDIR)/scc/scc/scc.h
./scc/posix/scc.o: $(INCDIR)/scc/scc/syscrts.h
./scc/posix/scc.o: $(INCDIR)/scc/scc/sysincludes.h
./scc/posix/scc.o: $(INCDIR)/scc/scc/syslibs.h
./scc/posix/scc.o: ./scc/posix/config.h
./size.o: $(INCDIR)/scc/scc/arg.h
./size.o: $(INCDIR)/scc/scc/mach.h
./strip.o: $(INCDIR)/scc/scc/arg.h
./strip.o: $(INCDIR)/scc/scc/mach.h
