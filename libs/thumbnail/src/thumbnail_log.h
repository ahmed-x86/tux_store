#pragma once
// Internal logging category for libthumbnail.
// Do NOT include this header from public (installed) headers — it exposes
// Qt internals that external consumers should not depend on.

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(logIcon)
