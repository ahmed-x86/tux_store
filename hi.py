import subprocess
import time

def get_changed_files():
    # استخدام -uall لفك أي مجلدات جديدة لملفات فردية لزيادة عدد الـ Commits
    result = subprocess.run(['git', 'status', '--porcelain', '-uall'], capture_output=True, text=True)
    files = []
    
    for line in result.stdout.splitlines():
        # تجاهل أول 3 حروف (حالة الملف) واستخراج المسار
        file_path = line[3:].strip()
        
        # معالجة علامات التنصيص إذا كان اسم الملف يحتوي على مسافات
        if file_path.startswith('"') and file_path.endswith('"'):
            file_path = file_path[1:-1]
            
        files.append(file_path)
        
    return files

def main():
    files = get_changed_files()
    
    if not files:
        print("لا توجد ملفات معدلة لرفعها.")
        return

    print(f"تم العثور على {len(files)} ملف. جاري العمل...")

    for file in files:
        print(f"-> معالجة: {file}")
        
        # 1. إضافة الملف
        subprocess.run(['git', 'add', file])
        
        # 2. عمل Commit
        subprocess.run(['git', 'commit', '-m', '.'])
        
        # تأخير ثانية واحدة لضمان تسجيل توقيت مختلف لكل Commit (يساعد في دقة الـ Graph)
        time.sleep(1)
        
        # 3. الرفع (Push)
        subprocess.run(['git', 'push', 'origin', 'main'])

    print("\n✅ تمت العملية بنجاح! الجراف هينور 🟩😎")

if __name__ == "__main__":
    main()