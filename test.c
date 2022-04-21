volatile unsigned int * const UART0DR = (unsigned int *)0x101f1000;

void print_uart0(const char *s)
{
	while(*s != '\0') {
		*UART0DR = (unsigned int)(*s);
		s++;
	}
}

void c_entry() {
    int i;
    unsigned int r=0;
    for (i=0;i<2123456789;i++)r+=i;
    char greet[] = "Hello World xxxxxxxx\n";
    for (i=0;i<8;i++) {
        greet[i+12]=(r%16 <= 9)? r%16 + '0': r%16 + 'a' - 10;
        r/=16;
    }
    print_uart0(greet);
}
