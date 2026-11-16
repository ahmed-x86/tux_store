---
name: Arabic-rtl-best-practices
description: >-
  Implement right-to-left (RTL) layouts for Arabic web and mobile applications.
  Use when user asks about RTL layout, Arabic text direction, bidirectional
  (bidi) text, Arabic CSS, "right to left", or needs to build Arabic UI. Covers
  CSS logical properties, Tailwind RTL, React/Next.js RTL setup, Arabic typography, and
  font selection. Do NOT use for Arabic RTL (similar but different typography)
  unless user explicitly asks for shared RTL patterns.
license: MIT
compatibility: 'Works with Claude Code, Claude.ai, Cursor. No network required.'
---

# أفضل الممارسات الموصى بها لـ RTL في العربية

## الإرشادات

### الخطوة 1: تحديد اتجاه المستند
ابدأ دائماً بخاصية HTML (وليس فقط CSS):

```html
<html lang="ar" dir="rtl">
```

هذا يخبر المتصفحات وقارئات الشاشة و CSS باستخدام RTL كاتجاه أساسي.

### الخطوة 2: خصائص CSS المنطقية
لا تستخدم أبداً الخصائص الاتجاهية الفيزيائية للتخطيط:

| فيزيائي (تجنبه) | منطقي (استخدمه) |
|-------------------|-----------------|
| `margin-left` | `margin-inline-start` |
| `margin-right` | `margin-inline-end` |
| `padding-left` | `padding-inline-start` |
| `padding-right` | `padding-inline-end` |
| `border-left` | `border-inline-start` |
| `text-align: left` | `text-align: start` |
| `text-align: right` | `text-align: end` |
| `float: left` | `float: inline-start` |
| `left: 10px` | `inset-inline-start: 10px` |

بهذه الطريقة ينعكس التخطيط تلقائياً في وضع RTL.

### الخطوة 3: التعامل مع النص ثنائي الاتجاه
عند دمج العربية مع الإنجليزية/الأرقام:

```css
/* عزل محتوى LTR المضمن */
.ltr-content {
  unicode-bidi: isolate;
  direction: ltr;
}

/* للعناصر المضمنة ذات المحتوى المختلط */
.bidi-override {
  unicode-bidi: bidi-override;
}
```

مشاكل bidi الشائعة:
- أرقام الهاتف تظهر معكوسة: نلفها بـ `<bdo dir="ltr">`
- علامات الترقيم في الطرف الخاطئ من الجملة: نستخدم `unicode-bidi: isolate`
- عناوين URL/البريد الإلكتروني داخل نص عربي: نلفها بـ `<span dir="ltr">`

### الخطوة 4: الطباعة العربية
مكدس الخطوط الموصى به:
```css
font-family: 'Tajawal', 'Alexandria', 'Cairo', 'Noto Sans Arabic', sans-serif;
```

إعدادات الطباعة:
```css
body[dir="rtl"] {
  font-size: 16px; /* العربية تحتاج إلى حجم أكبر قليلاً من اللاتينية */
  line-height: 1.7;
  letter-spacing: normal; /* لا تضف أبداً تباعد الأحرف للعربية */
  word-spacing: 0.05em; /* تباعد الكلمات البسيط يحسن القراءة */
}
```

### الخطوة 5: الإعداد حسب الإطار

**Tailwind CSS RTL (v3.3+ / v4):**

من الأفضل استخدام أدوات الخصائص المنطقية بدلاً من متغيرات `rtl:`/`ltr:`:

| فئة فيزيائية | فئة منطقية | خاصية CSS |
|-----------|-----------|-----------|
| `ml-4` | `ms-4` | `margin-inline-start` |
| `mr-4` | `me-4` | `margin-inline-end` |
| `pl-4` | `ps-4` | `padding-inline-start` |
| `pr-4` | `pe-4` | `padding-inline-end` |
| `left-4` | `start-4` | `inset-inline-start` |
| `right-4` | `end-4` | `inset-inline-end` |
| `rounded-l-lg` | `rounded-s-lg` | `border-start-start-radius` + `border-end-start-radius` |
| `rounded-r-lg` | `rounded-e-lg` | `border-start-end-radius` + `border-end-end-radius` |

```html
<!-- سيء: يتطلب فئتين، ينقطع بدون خاصية dir -->
<div class="ltr:ml-4 rtl:mr-4">...</div>

<!-- جيد: فئة واحدة، تنعكس تلقائياً حسب dir -->
<div class="ms-4">...</div>
```

احفظ متغيرات `rtl:` / `ltr:` فقط للحالات التي لا تغطيها الخصائص المنطقية (الرموز الاتجاهية، التحويلات وما شابه).

**ملاحظة لـ Tailwind v4:** الإصدار 4 يستخدم تكوين قائم على CSS (`@import "tailwindcss"` في CSS) بدلاً من `tailwind.config.js`. الخصائص المنطقية تعمل بنفس الطريقة في الإصدارات 3 و 4.

**Next.js App Router:**
```tsx
// app/layout.tsx
import { Tajawal } from 'next/font/google';

const tajawal = Tajawal({
  subsets: ['arabic', 'latin'],
  weight: ['400', '500', '700'],
});

export default async function RootLayout({
  children,
  params,
}: {
  children: React.ReactNode;
  params: Promise<{ locale: string }>;
}) {
  const { locale } = await params;
  const isRTL = locale === 'ar';

  return (
    <html lang={locale} dir={isRTL ? 'rtl' : 'ltr'}>
      <body className={tajawal.className}>{children}</body>
    </html>
  );
}
```

`next/font` يحفظ الخط محلياً (بدون طلبات خارجية لـ Google Fonts، بدون تحول التخطيط).

**React مع MUI:**
```jsx
import { createTheme, ThemeProvider } from '@mui/material/styles';
import { CacheProvider } from '@emotion/react';
import createCache from '@emotion/cache';
import rtlPlugin from 'stylis-plugin-rtl';
import { prefixer } from 'stylis';

const cacheRtl = createCache({
  key: 'muirtl',
  stylisPlugins: [prefixer, rtlPlugin],
});

const theme = createTheme({ direction: 'rtl' });
```

### الخطوة 6: الفخاخ الشائعة التي يجب التحقق منها
1. الرموز ذات المعنى الاتجاهي (الأسهم، أزرار الرجوع) - يجب أن تنعكس
2. أشرطة التقدم - يجب أن تمتلئ من اليمين إلى اليسار
3. المنزلقات/الدوارات - يجب أن ينعكس اتجاه التمرير
4. تسميات النماذج - يجب أن تكون محاذاة لليمين
5. فتات الخبز (breadcrumbs) - يجب أن ينعكس اتجاه الفاصل
6. الجداول - محاذاة الرؤوس والخلايا
7. الرسوم البيانية - قد يحتاج محور X إلى الانعكاس للقراء العرب

## أمثلة

### المثال 1: تحويل مكون LTR إلى RTL
يقول المستخدم: "اجعل مكون البطاقة هذا يعمل مع العربية"

قبل (LTR فقط):
```css
.card {
  margin-left: 16px;
  padding-right: 12px;
  text-align: left;
  border-left: 3px solid blue;
}
```

بعد (متوافق مع RTL):
```css
.card {
  margin-inline-start: 16px;
  padding-inline-end: 12px;
  text-align: start;
  border-inline-start: 3px solid blue;
}
```

في Tailwind، نستبدل `ml-4 pr-3 text-left border-l-4` بـ `ms-4 pe-3 text-start border-s-4`.

### المثال 2: مشكلة النص ثنائي الاتجاه
يقول المستخدم: "الأرقام تظهر معكوسة في نصي العربي"

```html
<!-- خطأ: يظهر رقم الهاتف معكوساً -->
<p>اتصل بنا: 050-321-4450</p>

<!-- صحيح: عزل محتوى LTR -->
<p>اتصل بنا: <span dir="ltr">050-321-4450</span></p>
```

يمكن استخدام `unicode-bidi: isolate` على span المحتوي لحل قائم على CSS فقط.

### المثال 3: التنقل RTL في Tailwind
يقول المستخدم: "الشريط الجانبي الخاص بي في الجانب الخاطئ في العربية"

```html
<!-- سيء: الشريط الجانبي عالق على اليسار -->
<aside class="fixed left-0 w-64">...</aside>

<!-- جيد: الشريط الجانبي ينعكس تلقائياً -->
<aside class="fixed start-0 w-64">...</aside>

<!-- رمز السهم للخلف يتطلب متغير rtl: -->
<button class="rtl:rotate-180">
  <ArrowLeftIcon />
</button>
```

## الموارد المرفقة

### ملفات مساعدة
- `references/css-logical-properties.md` - جدول تعيين كامل من خصائص CSS الفيزيائية إلى المنطقية (الهامش والحشو والحدود والموضع ومحاذاة النص والأحجام) بالإضافة إلى توصيات لمكدسات الخطوط العربية لـ sans-serif و serif و monospace. انظر إليه عند تحويل ورقة أنماط LTR إلى خصائص منطقية متوافقة مع RTL أو اختيار خطوط ويب عربية.

## الفخاخ الشائعة
- CSS text-align: left خطأ للعربية. استخدم text-align: start الذي يحترم اتجاه المستند. الوكلاء يميلون إلى ترميز محاذاة يسار في CSS.
- margin-left و padding-right لا ينعكسان في وضع RTL. استخدم خصائص CSS المنطقية: margin-inline-start و padding-inline-end بدلاً من ذلك. الوكلاء المدربون على CSS من LTR سينتجون خصائص فيزيائية.
- اتجاه الصف في Flexbox ينعكس تلقائياً في RTL، لكن row-reverse ينعكس أيضاً، مما يسبب انعكاس مزدوج والعودة إلى ترتيب LTR. قد يضيف الوكلاء row-reverse لأنهم يعتقدون أنه ينشئ RTL، لكن في الواقع ينشئ LTR في سياق RTL.
- أرقام الهاتف وأرقام بطاقات الائتمان وأجزاء الكود يجب أن تبقى LTR حتى داخل حاويات RTL. لفها بـ bdo dir="ltr" أو استخدم direction: ltr على العنصر المحتوي. يترك الوكلاء أحياناً لهم الشبكة RTL.

## روابط المساعدة

| المصدر | العنوان | ما يجب التحقق منه |
|------|-------|----------|
| خصائص CSS المنطقية في MDN | https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_logical_properties_and_values | قائمة خصائص كاملة وجداول دعم المتصفح |
| دعم RTL في Tailwind CSS | https://tailwindcss.com/docs/hover-focus-and-other-states#rtl-support | بناء جملة متغيرات `rtl:` / `ltr:` |
| الخصائص المنطقية في Tailwind | https://tailwindcss.com/docs/margin#logical-properties | أدوات `ms-*`, `me-*`, `ps-*`, `pe-*` |
| Google Fonts العربية | https://fonts.google.com/?subset=arabic | عائلات الخطوط العربية المتاحة |
| W3C الدولية | https://www.w3.org/International/articles/inline-bidi-markup/ | خوارزمية bidi من Unicode وأفضل الممارسات |

## استكشاف الأخطاء

### خطأ: "محاذاة النص تبدو خاطئة"
السبب: استخدام `text-align: left` بدلاً من `text-align: start`
الحل: استبدل كل `left`/`right` في text-align بـ `start`/`end`.

### خطأ: "التخطيط لا ينعكس"
السبب: استخدام margin/padding فيزيائي بدلاً من الخصائص المنطقية
الحل: استبدل كل `margin-left`/`margin-right` بـ `margin-inline-start`/`margin-inline-end`.
