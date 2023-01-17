#==============================================================================#
#                                   COMMANDS                                   #
#==============================================================================#

MAKE_SILENT = make --no-print-directory

#==============================================================================#
#                                   MAKEFILE                                   #
#==============================================================================#

fclean :
	$(MAKE_SILENT) fclean -C cpp00/ex00
	$(MAKE_SILENT) fclean -C cpp00/ex01
	$(MAKE_SILENT) fclean -C cpp00/ex02

	$(MAKE_SILENT) fclean -C cpp01/ex00
	$(MAKE_SILENT) fclean -C cpp01/ex01
	$(MAKE_SILENT) fclean -C cpp01/ex02
	$(MAKE_SILENT) fclean -C cpp01/ex03
	$(MAKE_SILENT) fclean -C cpp01/ex04
	$(MAKE_SILENT) fclean -C cpp01/ex05
	$(MAKE_SILENT) fclean -C cpp01/ex06

	$(MAKE_SILENT) fclean -C cpp02/ex00
	$(MAKE_SILENT) fclean -C cpp02/ex01
	$(MAKE_SILENT) fclean -C cpp02/ex02
	$(MAKE_SILENT) fclean -C cpp02/ex03

	$(MAKE_SILENT) fclean -C cpp03/ex00
	$(MAKE_SILENT) fclean -C cpp03/ex01
	$(MAKE_SILENT) fclean -C cpp03/ex02
	$(MAKE_SILENT) fclean -C cpp03/ex03

	$(MAKE_SILENT) fclean -C cpp04/ex00
	$(MAKE_SILENT) fclean -C cpp04/ex01
	$(MAKE_SILENT) fclean -C cpp04/ex02
	$(MAKE_SILENT) fclean -C cpp04/ex03

	# $(MAKE_SILENT) fclean -C cpp05/ex00
	# $(MAKE_SILENT) fclean -C cpp05/ex01
	# $(MAKE_SILENT) fclean -C cpp05/ex02
	# $(MAKE_SILENT) fclean -C cpp05/ex03

	# $(MAKE_SILENT) fclean -C cpp06/ex00
	# $(MAKE_SILENT) fclean -C cpp06/ex01
	# $(MAKE_SILENT) fclean -C cpp06/ex02

	# $(MAKE_SILENT) fclean -C cpp07/ex00
	# $(MAKE_SILENT) fclean -C cpp07/ex01
	# $(MAKE_SILENT) fclean -C cpp07/ex02

	# $(MAKE_SILENT) fclean -C cpp08/ex00
	# $(MAKE_SILENT) fclean -C cpp08/ex01
	# $(MAKE_SILENT) fclean -C cpp08/ex02

.PHONY : fclean
.SILENT :