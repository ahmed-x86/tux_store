#!/bin/bash
# يحاول يجيب رقم الإصدار من صفحة التحميلات الرسمية أولاً
page="$(curl -fsSL --max-time 15 "https://paper.design/downloads" 2>/dev/null)"
v="$(printf '%s' "$page" | grep -oE 'v?[0-9]+\.[0-9]+\.[0-9]+' | grep -oE '[0-9]+\.[0-9]+\.[0-9]+' | head -n1)"

# احتياط: استخرجه من اسم الملف الفعلي بعد إعادة التوجيه
if [ -z "$v" ]; then
    final="$(curl -sIL -o /dev/null -w '%{url_effective}' --max-time 15 "https://download.paper.design/linux/appImage/x64" 2>/dev/null)"
    v="$(basename "$final" | grep -oE '[0-9]+\.[0-9]+\.[0-9]+' | head -n1)"
fi

printf '%s\n' "${v:-unknown}"
