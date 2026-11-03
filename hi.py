#!/usr/bin/env python3
import subprocess
import sys

def run_cmd(cmd):
    result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    return result.returncode, result.stdout.strip(), result.stderr.strip()

def main():
    # التحقق من الملفات المعدلة وغير المتتبعة
    code, out, err = run_cmd(["git", "status", "--porcelain"])
    if code != 0:
        print(f"خطأ أثناء قراءة git status:\n{err}", file=sys.stderr)
        sys.exit(1)

    if not out:
        print("المستودع نظيف، لا توجد تغييرات للرفع.")
        return

    # جمع مسارات الملفات فقط وتجاهل الدلائل الفارغة أو الرموز
    files = []
    for line in out.splitlines():
        if len(line) > 3:
            # أول خانتين لحالة الملف ثم مسافة ثم اسم المسار
            file_path = line[3:].strip()
            # التعامل مع الملفات التي تم تغيير اسمها (old -> new)
            if " -> " in file_path:
                file_path = file_path.split(" -> ")[1].strip()
            # إزالة علامات التنصيص إن وجدت
            file_path = file_path.strip('"')
            files.append(file_path)

    total = len(files)
    print(f"تم العثور على {total} ملف/مسار للتسجيل منفصلاً...\n")

    for idx, path in enumerate(files, 1):
        print(f"[{idx}/{total}] معالجة: {path}")
        
        # 1. إضافة الملف بمفرده
        add_code, _, add_err = run_cmd(["git", "add", path])
        if add_code != 0:
            print(f"  تحذير: فشل git add للمسار {path}: {add_err}")
            continue

        # 2. إنشاء الـ commit الخاص به
        msg = f"update {path}"
        commit_code, _, commit_err = run_cmd(["git", "commit", "-m", msg])
        if commit_code != 0:
            print(f"  تخطي: لا توجد تغييرات لتسجيلها لـ {path}")

    # 3. دفع جميع الـ commits دفعة واحدة
    print("\nجاري تنفيذ git push لجميع الـ commits...")
    push_code, push_out, push_err = run_cmd(["git", "push"])
    if push_code == 0:
        print("تم الرفع بنجاح!")
    else:
        print(f"فشل الـ push:\n{push_err}", file=sys.stderr)

if __name__ == "__main__":
    main()