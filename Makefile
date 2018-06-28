ASM_PATH = asm_dir/
VM_PATH = vm_dir/
ASM_NAME = asm
VM_NAME = corewar

.PHONY: all, clean, fclean, re, norme

all:
	make -C $(ASM_PATH)
	make -C $(VM_PATH)
	@cp $(ASM_PATH)asm/$(ASM_NAME) .
	@cp $(VM_PATH)$(VM_NAME) .

vm:
	make -C $(VM_PATH)
	@cp $(VM_PATH)$(VM_NAME) .

asm:
	make -C $(ASM_PATH)
	@cp $(ASM_PATH)asm/$(ASM_NAME) .

clean:
	make clean -C $(ASM_PATH)
	make clean -C $(VM_PATH)
	@rm -f $(ASM_NAME)
	@rm -f $(VM_NAME)

fclean: clean
	make fclean -C $(ASM_PATH)
	make fclean -C $(VM_PATH)

re: fclean all
