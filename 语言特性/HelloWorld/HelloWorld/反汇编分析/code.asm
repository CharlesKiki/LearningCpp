.text:004117F0 sub_4117F0      proc near               ; CODE XREF: sub_4112A3j
.text:004117F0
.text:004117F0 var_C0          = byte ptr -0C0h
.text:004117F0
.text:004117F0                 push    ebp      ;保护先前EBP指针， EBP入栈 这是栈底
.text:004117F1                 mov     ebp, esp ;设置EBP指针指向栈顶 栈顶出现了
.text:004117F3                 sub     esp, 0C0h;栈被分配的一定的空间
.text:004117F9                 push    ebx
.text:004117FA                 push    esi
.text:004117FB                 push    edi
.text:004117FC                 lea     edi, [ebp+var_C0]

.text:00411802                 mov     ecx, 30h
.text:00411807                 mov     eax, 0CCCCCCCCh
.text:0041180C                 rep stosd
.text:0041180E                 mov     ecx, offset unk_41C003
.text:00411813                 call    sub_41120D
.text:00411818                 push    offset aHelloWorld_ ; "Hello,World."

.text:0041181D                 call    sub_41104B
.text:00411822                 add     esp, 4
.text:00411825                 xor     eax, eax
.text:00411827                 pop     edi
.text:00411828                 pop     esi
.text:00411829                 pop     ebx
.text:0041182A                 add     esp, 0C0h
.text:00411830                 cmp     ebp, esp
.text:00411832                 call    sub_411217
.text:00411837                 mov     esp, ebp
.text:00411839                 pop     ebp
.text:0041183A                 retn
.text:0041183A sub_4117F0      endp
.text:0041183A