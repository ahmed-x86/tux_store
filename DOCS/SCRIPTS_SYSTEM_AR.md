# الإضافات التفاعلية (Scripts) — ملخص بالعربي

الشرح الكامل بالإنجليزية في [SCRIPTS_SYSTEM.md](SCRIPTS_SYSTEM.md). هذا ملخص سريع لإنشاء إضافة جديدة.

## الفكرة
الإضافة (Script) هي **ملف JSON واحد** يصف خطوات التثبيت وخطوات الإزالة. يظهر في المتجر مثل أي برنامج (بحث، الصفحة الرئيسية، صفحة خاصة به). ويمكن أن تظهر أيضًا في صفحة **التصنيفات** بإضافة `"categories"` (أو `"category"` القديم) كما في المثال أدناه. لا تحتاج لكتابة Rust ولا لإعادة بناء المشروع.

## 1) أين أضع الملف؟
- `data/scripts/اسم-الاضافة-id-1.json` — إضافات تأتي مع المتجر (موثوقة).
- `~/.config/tux-store/scripts/` — إضافات المستخدم (غير موثوقة: يعرض المتجر كل أمر يحتاج صلاحيات المدير ويطلب الموافقة).
- ملف واحد لكل إضافة وبدون مجلدات فرعية. الأيقونة (`"file"`) تكون بجانب الـ JSON.
- ملف فيه خطأ يُتجاهل ويُسجَّل في اللوج، والمتجر يكمل التشغيل. أي مفتاح غير معروف يعتبر خطأ (حتى لا يمر خطأ إملائي بصمت).
- الـ `id` أحرف صغيرة وأرقام و `- _ . +` فقط، ولا تغيّره بعد النشر لأنه اسم ملف البصمة.

## 2) هيكل الملف
```json
{
  "schema": 2, "id": "my-tool-id-1", "title": "My Tool",
  "description": "وصف قصير", "version": "1.0", "author": "me",
  "keywords": ["tool", "أداة"], "show_on_home": true,
  "categories": ["graphics", "artcraft"],  // تصنيفات AppStream و/أو تصنيفات إضافية من data/addon_categories/
  "start": "welcome",          // أول خطوة في التثبيت
  "uninstall": "un_confirm",   // أول خطوة في الإزالة (بدونها لا يظهر زر Uninstall)
  "steps": { ... }
}
```

أنواع الخطوات (`type`): `dialog` رسالة وأزرار · `choice` اختيار · `check` أمر صامت (لا يعمل بصلاحيات root أبدًا) · `run` أوامر ظاهرة مع شريط تقدم (`"root": true` تشغّله عبر pkexec) · `branch` تفرّع حسب شرط · `set` تعيين متغيرات · `print` طباعة في الترمنال · `record` حفظ البصمة · `finish` إنهاء.

`show_on_home` والتصنيفات مستقلة: الأول يضع الإضافة في رفّ الصفحة الرئيسية، والتصنيفات تضعها في صفحة التصنيفات حتى لو كان `show_on_home` مساويًا `false`. يقبل `categories` قائمة أسماء، كل اسم إما معرّف AppStream (`utilities`, `developer-tools`, `games` …) أو عنوانه (`Utilities`)، أو معرّف تصنيف إضافي من `data/addon_categories/` (`artcraft`) أو عنوانه (`ArtCraft`). يتجاهل حالة الأحرف والفراغات و `& _ -`، ويمكن الجمع بين `category` المفرد و`categories` في نفس الملف. التصنيف الإضافي يُعرض قبل تصنيفات AppStream. إذا لم يوجد اسم على الجهاز يُسجَّل تحذير وتبقى الإضافة في بقية تصنيفاتها وفي البحث والرئيسية.

### تصنيفات إضافية (Add-on categories)

مجلد باسم التصنيف داخل `data/addon_categories/` (أو `~/.config/tux-store/addon_categories/`)، بداخله JSON بنفس الاسم وصورة اختيارية:

```
data/addon_categories/artcraft/artcraft.json
data/addon_categories/artcraft/artcraft.svg
```

```json
{
  "schema": 1,
  "id": "artcraft",
  "title": "ArtCraft",
  "description": "تطبيقات عائلة ArtCraft.",
  "icon": { "file": "artcraft.svg" }
}
```

`icon` يحدد **مصدرًا واحدًا** فقط: `{"file": "x.svg"}` صورة بجانب الـ JSON، أو `{"url": "https://…"}` رابط على مضيف موثوق، أو `{"flathub": "org.gnome.Builder"}` معرّف تطبيق في Flathub فقط والمتجر يبني الرابط بنفسه. التفاصيل الكاملة في [TAXONOMY.md](TAXONOMY.md#custom-add-on-categories).

المتغيرات: في النصوص `${name}`، وفي أوامر الـ shell تُقرأ من `"$TUX_VAR_NAME"` (بين علامتي تنصيص دائمًا).

## 3) التثبيت
`start` → `dialog` (شرح) → `check` (فحص الأدوات/الإنترنت) → `run` (التنفيذ) → **`record`** (تسجيل ما تم) → `finish` مع `"mark": "installed"`.
ضع `record` **بعد نجاح الأوامر** مباشرة قبل `finish`.

## 4) الإزالة
يظهر زر Uninstall فقط إذا كان في الملف `uninstall` **ويوجد** ملف بصمة للإضافة.
تبدأ من خطوة `uninstall` وترى بيانات البصمة كمتغيرات:
- `${recorded_files}` ملفات (كل ملف في سطر) · `${recorded_packages}` حزم pacman · `${installed_version}` · وكل اختيارات المستخدم أثناء التثبيت.

تنتهي بـ `finish` مع `"mark": "uninstalled"` فتُحذف البصمة. لو فشلت الإزالة **لا تضع mark** حتى تبقى البصمة ويعيد المستخدم المحاولة.

## 5) البصمات (Receipts)
ملف JSON يكتبه المحرك في `~/.local/share/tux-store/addons/<id>.json`. بوجوده تظهر كلمة **Installed**، ومنه تقرأ خطوات الإزالة.

| الحقل | المعنى |
|---|---|
| `complete` | `false` إذا التثبيت لم يكتمل |
| `installed_at` / `installed_version` | وقت وإصدار التثبيت |
| `vars` | اختيارات المستخدم |
| `values` | قيم طلبتَ حفظها بـ `record.set` |
| `packages` | حزم pacman المسجّلة |
| `files` | ملفات/مجلدات (مسار كامل أو `~/…`؛ ممنوع `..` و `/`) |

حذف ملف البصمة يدويًا = المتجر ينسى أن الإضافة مثبتة.

## 6) فحص الملف قبل النشر
```bash
tux-store --check-script my-tool-id-1.json
```
يفحص الملف بنفس كود المتجر، ويشرح الخطأ (مفتاح خاطئ الإملاء، مفتاح ناقص، JSON مكسور) وينتهي بكود خروج 1. وإذا الملف سليم يعرض تحذيرات: خطوات لا يصل إليها شيء، غياب `mark`، غياب `uninstall` أو `record`، أيقونة غير موجودة، وقائمة الأوامر التي تحتاج صلاحيات المدير.

## 7) تجربة
`TUX_LOG=debug ./target/debug/tux-store` ← افتح صفحة الإضافة ← ثبّت ← أزل، وراقب مجلد البصمات. أفضل نماذج جاهزة: `hello-test-id-2.json` (كل أنواع الخطوات) و `nvidia-drivers-id-1.json`.
