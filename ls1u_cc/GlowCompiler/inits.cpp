void init(int argc, char* argv[]) {
	{extern void string_init(void); string_init(); }
	{extern void decl_init(void); decl_init(); }
	{extern void prof_init(void); prof_init(); }
	{extern void dag_init(void); dag_init(); }
	{extern void error_init(void); error_init(); }
	{extern void event_init(void); event_init(); }
	{extern void expr_init(void); expr_init(); }
	{extern void gen_init(void); gen_init(); }
	{extern void init_init(void); init_init(); }
	{extern void list_init(void); list_init(); }
	{extern void profio_init(void); profio_init(); }
	{extern void simp_init(void); simp_init(); }
	{extern void stab_init(void); stab_init(); }
	{extern void stmt_init(void); stmt_init(); }
	{extern void sym_init(void); sym_init(); }
	{extern void trace_init(void); trace_init(); }
	{extern void tree_init(void); tree_init(); }
	{extern void _main_init(void); _main_init(); }
	{extern void input_init(int, char* []); input_init(argc, argv); }
	{extern void type_init(int, char* []); type_init(argc, argv); }
}
