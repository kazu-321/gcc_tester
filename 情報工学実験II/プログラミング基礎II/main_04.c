#include <stdio.h>
#include <regex.h>
#include <string.h>

int main(void) {
    const char regex[] = "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}";
    regex_t preg;
    char str[] = "今日は090-7623-8765宛に電話をかけましたが,誰も出ませんでした. アドレスとしてhoge@domain.jpを指定して電子メールを送りましたが返信がありません. 代表電話番号である029-271-2800に電話をかけたところ,代表者が電話に出ました. 代表者に電子メールアドレスを訪ねたところ,daihyo@hogehoge.comとのことでした.";
    regmatch_t pm[1];

    if (regcomp(&preg, regex, REG_EXTENDED) != 0) {
        printf("regex is not available.\n");
        return 1;
    }

    const char *p = str;
    while (regexec(&preg, p, 1, pm, 0) == 0) {
        printf("メールアドレス");
        for (int i = pm[0].rm_so; i < pm[0].rm_eo; i++) {
            putchar(p[i]);
        }
        printf("\n");
        p += pm[0].rm_eo;
    }

    regfree(&preg);
    return 0;
}
