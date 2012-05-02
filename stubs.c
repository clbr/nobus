#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct DBusAddressEntry DBusAddressEntry;
dbus_bool_t dbus_parse_address (const char *address,
 DBusAddressEntry ***entry,
 int *array_len,
 DBusError *error);
const char *dbus_address_entry_get_value (DBusAddressEntry *entry,
 const char *key);
const char *dbus_address_entry_get_method (DBusAddressEntry *entry);
char* dbus_address_escape_value (const char *value);
char* dbus_address_unescape_value (const char *value,
 DBusError *error);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
DBusConnection *dbus_bus_get (DBusBusType type,
 DBusError *error);
DBusConnection *dbus_bus_get_private (DBusBusType type,
 DBusError *error);
dbus_bool_t dbus_bus_register (DBusConnection *connection,
 DBusError *error);
dbus_bool_t dbus_bus_set_unique_name (DBusConnection *connection,
 const char *unique_name);
const char* dbus_bus_get_unique_name (DBusConnection *connection);
unsigned long dbus_bus_get_unix_user (DBusConnection *connection,
 const char *name,
 DBusError *error);
char* dbus_bus_get_id (DBusConnection *connection,
 DBusError *error);
int dbus_bus_request_name (DBusConnection *connection,
 const char *name,
 unsigned int flags,
 DBusError *error);
int dbus_bus_release_name (DBusConnection *connection,
 const char *name,
 DBusError *error);
dbus_bool_t dbus_bus_name_has_owner (DBusConnection *connection,
 const char *name,
 DBusError *error);
dbus_bool_t dbus_bus_start_service_by_name (DBusConnection *connection,
 const char *name,
 dbus_uint32_t flags,
 dbus_uint32_t *reply,
 DBusError *error);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct DBusWatch DBusWatch;
typedef struct DBusTimeout DBusTimeout;
typedef struct DBusPreallocatedSend DBusPreallocatedSend;
typedef struct DBusPendingCall DBusPendingCall;
typedef struct DBusConnection DBusConnection;
typedef struct DBusObjectPathVTable DBusObjectPathVTable;
typedef enum
{
 DBUS_WATCH_READABLE = 1 << 0,
 DBUS_WATCH_WRITABLE = 1 << 1,
 DBUS_WATCH_ERROR = 1 << 2,
 DBUS_WATCH_HANGUP = 1 << 3
} DBusWatchFlags;
typedef enum
{
 DBUS_DISPATCH_DATA_REMAINS,
 DBUS_DISPATCH_COMPLETE,
 DBUS_DISPATCH_NEED_MEMORY
} DBusDispatchStatus;
typedef dbus_bool_t (* DBusAddWatchFunction) (DBusWatch *watch,
 void *data);
typedef void (* DBusWatchToggledFunction) (DBusWatch *watch,
 void *data);
typedef void (* DBusRemoveWatchFunction) (DBusWatch *watch,
 void *data);
typedef dbus_bool_t (* DBusAddTimeoutFunction) (DBusTimeout *timeout,
 void *data);
typedef void (* DBusTimeoutToggledFunction) (DBusTimeout *timeout,
 void *data);
typedef void (* DBusRemoveTimeoutFunction) (DBusTimeout *timeout,
 void *data);
typedef void (* DBusDispatchStatusFunction) (DBusConnection *connection,
 DBusDispatchStatus new_status,
 void *data);
typedef void (* DBusWakeupMainFunction) (void *data);
typedef dbus_bool_t (* DBusAllowUnixUserFunction) (DBusConnection *connection,
 unsigned long uid,
 void *data);
typedef dbus_bool_t (* DBusAllowWindowsUserFunction) (DBusConnection *connection,
 const char *user_sid,
 void *data);
typedef void (* DBusPendingCallNotifyFunction) (DBusPendingCall *pending,
 void *user_data);
typedef DBusHandlerResult (* DBusHandleMessageFunction) (DBusConnection *connection,
 DBusMessage *message,
 void *user_data);
DBusConnection* dbus_connection_open (const char *address,
 DBusError *error);
DBusConnection* dbus_connection_open_private (const char *address,
 DBusError *error);
DBusConnection* dbus_connection_ref (DBusConnection *connection);
dbus_bool_t dbus_connection_get_is_connected (DBusConnection *connection);
dbus_bool_t dbus_connection_get_is_authenticated (DBusConnection *connection);
dbus_bool_t dbus_connection_get_is_anonymous (DBusConnection *connection);
char* dbus_connection_get_server_id (DBusConnection *connection);
dbus_bool_t dbus_connection_can_send_type (DBusConnection *connection,
 int type);
dbus_bool_t dbus_connection_read_write_dispatch (DBusConnection *connection,
 int timeout_milliseconds);
dbus_bool_t dbus_connection_read_write (DBusConnection *connection,
 int timeout_milliseconds);
DBusMessage* dbus_connection_borrow_message (DBusConnection *connection);
DBusMessage* dbus_connection_pop_message (DBusConnection *connection);
DBusDispatchStatus dbus_connection_get_dispatch_status (DBusConnection *connection);
DBusDispatchStatus dbus_connection_dispatch (DBusConnection *connection);
dbus_bool_t dbus_connection_has_messages_to_send (DBusConnection *connection);
dbus_bool_t dbus_connection_send (DBusConnection *connection,
 DBusMessage *message,
 dbus_uint32_t *client_serial);
dbus_bool_t dbus_connection_send_with_reply (DBusConnection *connection,
 DBusMessage *message,
 DBusPendingCall **pending_return,
 int timeout_milliseconds);
DBusMessage * dbus_connection_send_with_reply_and_block (DBusConnection *connection,
 DBusMessage *message,
 int timeout_milliseconds,
 DBusError *error);
dbus_bool_t dbus_connection_set_watch_functions (DBusConnection *connection,
 DBusAddWatchFunction add_function,
 DBusRemoveWatchFunction remove_function,
 DBusWatchToggledFunction toggled_function,
 void *data,
 DBusFreeFunction free_data_function);
dbus_bool_t dbus_connection_set_timeout_functions (DBusConnection *connection,
 DBusAddTimeoutFunction add_function,
 DBusRemoveTimeoutFunction remove_function,
 DBusTimeoutToggledFunction toggled_function,
 void *data,
 DBusFreeFunction free_data_function);
dbus_bool_t dbus_connection_get_unix_user (DBusConnection *connection,
 unsigned long *uid);
dbus_bool_t dbus_connection_get_unix_process_id (DBusConnection *connection,
 unsigned long *pid);
dbus_bool_t dbus_connection_get_adt_audit_session_data (DBusConnection *connection,
 void **data,
 dbus_int32_t *data_size);
dbus_bool_t dbus_connection_get_windows_user (DBusConnection *connection,
 char **windows_sid_p);
dbus_bool_t dbus_connection_add_filter (DBusConnection *connection,
 DBusHandleMessageFunction function,
 void *user_data,
 DBusFreeFunction free_data_function);
dbus_bool_t dbus_connection_allocate_data_slot (dbus_int32_t *slot_p);
dbus_bool_t dbus_connection_set_data (DBusConnection *connection,
 dbus_int32_t slot,
 void *data,
 DBusFreeFunction free_data_func);
void* dbus_connection_get_data (DBusConnection *connection,
 dbus_int32_t slot);
long dbus_connection_get_max_message_size (DBusConnection *connection);
long dbus_connection_get_max_received_size (DBusConnection *connection);
long dbus_connection_get_max_message_unix_fds (DBusConnection *connection);
long dbus_connection_get_max_received_unix_fds(DBusConnection *connection);
long dbus_connection_get_outgoing_size (DBusConnection *connection);
long dbus_connection_get_outgoing_unix_fds (DBusConnection *connection);
DBusPreallocatedSend* dbus_connection_preallocate_send (DBusConnection *connection);
typedef void (* DBusObjectPathUnregisterFunction) (DBusConnection *connection,
 void *user_data);
typedef DBusHandlerResult (* DBusObjectPathMessageFunction) (DBusConnection *connection,
 DBusMessage *message,
 void *user_data);
struct DBusObjectPathVTable
{
 DBusObjectPathUnregisterFunction unregister_function;
 DBusObjectPathMessageFunction message_function;
 void (* dbus_internal_pad1) (void *);
 void (* dbus_internal_pad2) (void *);
 void (* dbus_internal_pad3) (void *);
 void (* dbus_internal_pad4) (void *);
};
dbus_bool_t dbus_connection_try_register_object_path (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data,
 DBusError *error);
dbus_bool_t dbus_connection_register_object_path (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data);
dbus_bool_t dbus_connection_try_register_fallback (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data,
 DBusError *error);
dbus_bool_t dbus_connection_register_fallback (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data);
dbus_bool_t dbus_connection_unregister_object_path (DBusConnection *connection,
 const char *path);
dbus_bool_t dbus_connection_get_object_path_data (DBusConnection *connection,
 const char *path,
 void **data_p);
dbus_bool_t dbus_connection_list_registered (DBusConnection *connection,
 const char *parent_path,
 char ***child_entries);
dbus_bool_t dbus_connection_get_unix_fd (DBusConnection *connection,
 int *fd);
dbus_bool_t dbus_connection_get_socket (DBusConnection *connection,
 int *fd);
#ifndef DBUS_DISABLE_DEPRECATED
DBUS_DEPRECATED int dbus_watch_get_fd (DBusWatch *watch);
#endif
int dbus_watch_get_unix_fd (DBusWatch *watch);
int dbus_watch_get_socket (DBusWatch *watch);
unsigned int dbus_watch_get_flags (DBusWatch *watch);
void* dbus_watch_get_data (DBusWatch *watch);
dbus_bool_t dbus_watch_handle (DBusWatch *watch,
 unsigned int flags);
dbus_bool_t dbus_watch_get_enabled (DBusWatch *watch);
int dbus_timeout_get_interval (DBusTimeout *timeout);
void* dbus_timeout_get_data (DBusTimeout *timeout);
dbus_bool_t dbus_timeout_handle (DBusTimeout *timeout);
dbus_bool_t dbus_timeout_get_enabled (DBusTimeout *timeout);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct DBusError DBusError;
struct DBusError
{
 const char *name;
 const char *message;
 unsigned int dummy1 : 1;
 unsigned int dummy2 : 1;
 unsigned int dummy3 : 1;
 unsigned int dummy4 : 1;
 unsigned int dummy5 : 1;
 void *padding1;
};
dbus_bool_t dbus_error_has_name (const DBusError *error,
 const char *name);
dbus_bool_t dbus_error_is_set (const DBusError *error);
#endif
#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_DBus_Introspectable
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_Introspectable_introspect (DBusGProxy *proxy, char ** OUT_data, GError **error)
{
 return dbus_g_proxy_call (proxy, "Introspect", error, G_TYPE_INVALID, G_TYPE_STRING, OUT_data, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_Introspectable_introspect_reply) (DBusGProxy *proxy, char * OUT_data, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_Introspectable_introspect_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char * OUT_data;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_data, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_Introspectable_introspect_reply)data->cb) (proxy, OUT_data, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_Introspectable_introspect_async (DBusGProxy *proxy, org_freedesktop_DBus_Introspectable_introspect_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "Introspect", org_freedesktop_DBus_Introspectable_introspect_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif
#ifndef DBUS_GLIB_CLIENT_WRAPPERS_org_freedesktop_DBus
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_hello (DBusGProxy *proxy, char ** OUT_arg0, GError **error)
{
 return dbus_g_proxy_call (proxy, "Hello", error, G_TYPE_INVALID, G_TYPE_STRING, OUT_arg0, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_hello_reply) (DBusGProxy *proxy, char * OUT_arg0, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_hello_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char * OUT_arg0;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_arg0, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_hello_reply)data->cb) (proxy, OUT_arg0, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_hello_async (DBusGProxy *proxy, org_freedesktop_DBus_hello_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "Hello", org_freedesktop_DBus_hello_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_request_name (DBusGProxy *proxy, const char * IN_arg0, const guint IN_arg1, guint* OUT_arg2, GError **error)
{
 return dbus_g_proxy_call (proxy, "RequestName", error, G_TYPE_STRING, IN_arg0, G_TYPE_UINT, IN_arg1, G_TYPE_INVALID, G_TYPE_UINT, OUT_arg2, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_request_name_reply) (DBusGProxy *proxy, guint OUT_arg2, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_request_name_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 guint OUT_arg2;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_UINT, &OUT_arg2, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_request_name_reply)data->cb) (proxy, OUT_arg2, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_request_name_async (DBusGProxy *proxy, const char * IN_arg0, const guint IN_arg1, org_freedesktop_DBus_request_name_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "RequestName", org_freedesktop_DBus_request_name_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_UINT, IN_arg1, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_release_name (DBusGProxy *proxy, const char * IN_arg0, guint* OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "ReleaseName", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_UINT, OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_release_name_reply) (DBusGProxy *proxy, guint OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_release_name_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 guint OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_UINT, &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_release_name_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_release_name_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_release_name_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "ReleaseName", org_freedesktop_DBus_release_name_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_start_service_by_name (DBusGProxy *proxy, const char * IN_arg0, const guint IN_arg1, guint* OUT_arg2, GError **error)
{
 return dbus_g_proxy_call (proxy, "StartServiceByName", error, G_TYPE_STRING, IN_arg0, G_TYPE_UINT, IN_arg1, G_TYPE_INVALID, G_TYPE_UINT, OUT_arg2, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_start_service_by_name_reply) (DBusGProxy *proxy, guint OUT_arg2, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_start_service_by_name_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 guint OUT_arg2;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_UINT, &OUT_arg2, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_start_service_by_name_reply)data->cb) (proxy, OUT_arg2, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_start_service_by_name_async (DBusGProxy *proxy, const char * IN_arg0, const guint IN_arg1, org_freedesktop_DBus_start_service_by_name_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "StartServiceByName", org_freedesktop_DBus_start_service_by_name_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_UINT, IN_arg1, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_name_has_owner (DBusGProxy *proxy, const char * IN_arg0, gboolean* OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "NameHasOwner", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_BOOLEAN, OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_name_has_owner_reply) (DBusGProxy *proxy, gboolean OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_name_has_owner_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 gboolean OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_BOOLEAN, &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_name_has_owner_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_name_has_owner_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_name_has_owner_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "NameHasOwner", org_freedesktop_DBus_name_has_owner_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_list_names (DBusGProxy *proxy, char *** OUT_arg0, GError **error)
{
 return dbus_g_proxy_call (proxy, "ListNames", error, G_TYPE_INVALID, G_TYPE_STRV, OUT_arg0, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_list_names_reply) (DBusGProxy *proxy, char * *OUT_arg0, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_list_names_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char ** OUT_arg0;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_arg0, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_list_names_reply)data->cb) (proxy, OUT_arg0, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_list_names_async (DBusGProxy *proxy, org_freedesktop_DBus_list_names_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "ListNames", org_freedesktop_DBus_list_names_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_list_activatable_names (DBusGProxy *proxy, char *** OUT_arg0, GError **error)
{
 return dbus_g_proxy_call (proxy, "ListActivatableNames", error, G_TYPE_INVALID, G_TYPE_STRV, OUT_arg0, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_list_activatable_names_reply) (DBusGProxy *proxy, char * *OUT_arg0, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_list_activatable_names_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char ** OUT_arg0;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_arg0, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_list_activatable_names_reply)data->cb) (proxy, OUT_arg0, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_list_activatable_names_async (DBusGProxy *proxy, org_freedesktop_DBus_list_activatable_names_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "ListActivatableNames", org_freedesktop_DBus_list_activatable_names_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_add_match (DBusGProxy *proxy, const char * IN_arg0, GError **error)
{
 return dbus_g_proxy_call (proxy, "AddMatch", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_add_match_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_add_match_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_add_match_reply)data->cb) (proxy, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_add_match_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_add_match_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "AddMatch", org_freedesktop_DBus_add_match_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_remove_match (DBusGProxy *proxy, const char * IN_arg0, GError **error)
{
 return dbus_g_proxy_call (proxy, "RemoveMatch", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_remove_match_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_remove_match_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_remove_match_reply)data->cb) (proxy, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_remove_match_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_remove_match_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "RemoveMatch", org_freedesktop_DBus_remove_match_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_get_name_owner (DBusGProxy *proxy, const char * IN_arg0, char ** OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "GetNameOwner", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_STRING, OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_get_name_owner_reply) (DBusGProxy *proxy, char * OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_get_name_owner_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char * OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_get_name_owner_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_get_name_owner_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_get_name_owner_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "GetNameOwner", org_freedesktop_DBus_get_name_owner_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_list_queued_owners (DBusGProxy *proxy, const char * IN_arg0, char *** OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "ListQueuedOwners", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_STRV, OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_list_queued_owners_reply) (DBusGProxy *proxy, char * *OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_list_queued_owners_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char ** OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRV, &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_list_queued_owners_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_list_queued_owners_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_list_queued_owners_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "ListQueuedOwners", org_freedesktop_DBus_list_queued_owners_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_get_connection_unix_user (DBusGProxy *proxy, const char * IN_arg0, guint* OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "GetConnectionUnixUser", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_UINT, OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_get_connection_unix_user_reply) (DBusGProxy *proxy, guint OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_get_connection_unix_user_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 guint OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_UINT, &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_get_connection_unix_user_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_get_connection_unix_user_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_get_connection_unix_user_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "GetConnectionUnixUser", org_freedesktop_DBus_get_connection_unix_user_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_get_connection_unix_process_id (DBusGProxy *proxy, const char * IN_arg0, guint* OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "GetConnectionUnixProcessID", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, G_TYPE_UINT, OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_get_connection_unix_process_id_reply) (DBusGProxy *proxy, guint OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_get_connection_unix_process_id_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 guint OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_UINT, &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_get_connection_unix_process_id_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_get_connection_unix_process_id_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_get_connection_unix_process_id_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "GetConnectionUnixProcessID", org_freedesktop_DBus_get_connection_unix_process_id_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_get_connection_se_linux_security_context (DBusGProxy *proxy, const char * IN_arg0, GArray** OUT_arg1, GError **error)
{
 return dbus_g_proxy_call (proxy, "GetConnectionSELinuxSecurityContext", error, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID, dbus_g_type_get_collection ("GArray", G_TYPE_UCHAR), OUT_arg1, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_get_connection_se_linux_security_context_reply) (DBusGProxy *proxy, GArray *OUT_arg1, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_get_connection_se_linux_security_context_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 GArray* OUT_arg1;
 dbus_g_proxy_end_call (proxy, call, &error, dbus_g_type_get_collection ("GArray", G_TYPE_UCHAR), &OUT_arg1, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_get_connection_se_linux_security_context_reply)data->cb) (proxy, OUT_arg1, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_get_connection_se_linux_security_context_async (DBusGProxy *proxy, const char * IN_arg0, org_freedesktop_DBus_get_connection_se_linux_security_context_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "GetConnectionSELinuxSecurityContext", org_freedesktop_DBus_get_connection_se_linux_security_context_async_callback, stuff, g_free, G_TYPE_STRING, IN_arg0, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_reload_config (DBusGProxy *proxy, GError **error)
{
 return dbus_g_proxy_call (proxy, "ReloadConfig", error, G_TYPE_INVALID, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_reload_config_reply) (DBusGProxy *proxy, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_reload_config_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_reload_config_reply)data->cb) (proxy, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_reload_config_async (DBusGProxy *proxy, org_freedesktop_DBus_reload_config_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "ReloadConfig", org_freedesktop_DBus_reload_config_async_callback, stuff, g_free, G_TYPE_INVALID);
}
static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
org_freedesktop_DBus_get_id (DBusGProxy *proxy, char ** OUT_arg0, GError **error)
{
 return dbus_g_proxy_call (proxy, "GetId", error, G_TYPE_INVALID, G_TYPE_STRING, OUT_arg0, G_TYPE_INVALID);
}
typedef void (*org_freedesktop_DBus_get_id_reply) (DBusGProxy *proxy, char * OUT_arg0, GError *error, gpointer userdata);
static void
org_freedesktop_DBus_get_id_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
 DBusGAsyncData *data = (DBusGAsyncData*) user_data;
 GError *error = NULL;
 char * OUT_arg0;
 dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_STRING, &OUT_arg0, G_TYPE_INVALID);
 (*(org_freedesktop_DBus_get_id_reply)data->cb) (proxy, OUT_arg0, error, data->userdata);
 return;
}
static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
org_freedesktop_DBus_get_id_async (DBusGProxy *proxy, org_freedesktop_DBus_get_id_reply callback, gpointer userdata)
{
 DBusGAsyncData *stuff;
 stuff = g_new (DBusGAsyncData, 1);
 stuff->cb = G_CALLBACK (callback);
 stuff->userdata = userdata;
 return dbus_g_proxy_begin_call (proxy, "GetId", org_freedesktop_DBus_get_id_async_callback, stuff, g_free, G_TYPE_INVALID);
}
#endif
typedef struct _DBusGConnection DBusGConnection;
typedef struct _DBusGMessage DBusGMessage;
GType dbus_g_connection_get_g_type (void) G_GNUC_CONST;
GType dbus_g_message_get_g_type (void) G_GNUC_CONST;
DBusGConnection* dbus_g_connection_ref (DBusGConnection *connection);
DBusGMessage* dbus_g_message_ref (DBusGMessage *message);
GQuark dbus_g_error_quark (void);
typedef enum
{
DBUS_GERROR_FAILED,
DBUS_GERROR_NO_MEMORY,
DBUS_GERROR_SERVICE_UNKNOWN,
DBUS_GERROR_NAME_HAS_NO_OWNER,
DBUS_GERROR_NO_REPLY,
DBUS_GERROR_IO_ERROR,
DBUS_GERROR_BAD_ADDRESS,
DBUS_GERROR_NOT_SUPPORTED,
DBUS_GERROR_LIMITS_EXCEEDED,
DBUS_GERROR_ACCESS_DENIED,
DBUS_GERROR_AUTH_FAILED,
DBUS_GERROR_NO_SERVER,
DBUS_GERROR_TIMEOUT,
DBUS_GERROR_NO_NETWORK,
DBUS_GERROR_ADDRESS_IN_USE,
DBUS_GERROR_DISCONNECTED,
DBUS_GERROR_INVALID_ARGS,
DBUS_GERROR_FILE_NOT_FOUND,
DBUS_GERROR_FILE_EXISTS,
DBUS_GERROR_UNKNOWN_METHOD,
DBUS_GERROR_TIMED_OUT,
DBUS_GERROR_MATCH_RULE_NOT_FOUND,
DBUS_GERROR_MATCH_RULE_INVALID,
DBUS_GERROR_SPAWN_EXEC_FAILED,
DBUS_GERROR_SPAWN_FORK_FAILED,
DBUS_GERROR_SPAWN_CHILD_EXITED,
DBUS_GERROR_SPAWN_CHILD_SIGNALED,
DBUS_GERROR_SPAWN_FAILED,
DBUS_GERROR_UNIX_PROCESS_ID_UNKNOWN,
DBUS_GERROR_INVALID_SIGNATURE,
DBUS_GERROR_INVALID_FILE_CONTENT,
DBUS_GERROR_SELINUX_SECURITY_CONTEXT_UNKNOWN,
DBUS_GERROR_REMOTE_EXCEPTION
} DBusGError;
gboolean dbus_g_error_has_name (GError *error,
 const char *name);
const char * dbus_g_error_get_name (GError *error);
DBusGConnection* dbus_g_connection_open (const gchar *address,
 GError **error);
DBusGConnection* dbus_g_bus_get (DBusBusType type,
 GError **error);
typedef struct _DBusGObjectInfo DBusGObjectInfo;
typedef struct _DBusGMethodInfo DBusGMethodInfo;
struct _DBusGMethodInfo
{
 GCallback function;
 GClosureMarshal marshaller;
 int data_offset;
};
struct _DBusGObjectInfo
{
 int format_version;
 const DBusGMethodInfo *method_infos;
 int n_method_infos;
 const char *data;
 const char *exported_signals;
 const char *exported_properties;
};
GObject * dbus_g_connection_lookup_g_object (DBusGConnection *connection,
 const char *at_path);
#ifdef DBUS_COMPILATION
#else
#endif
GType dbus_g_object_path_get_g_type (void) G_GNUC_CONST;
typedef struct _DBusGProxy DBusGProxy;
typedef struct _DBusGProxyClass DBusGProxyClass;
struct _DBusGProxy
{
 GObject parent;
};
struct _DBusGProxyClass
{
 GObjectClass parent_class;
};
typedef struct _DBusGProxyCall DBusGProxyCall;
typedef void (* DBusGProxyCallNotify) (DBusGProxy *proxy,
 DBusGProxyCall *call_id,
 void *user_data);
GType dbus_g_proxy_get_type (void) G_GNUC_CONST;
DBusGProxy* dbus_g_proxy_new_for_name (DBusGConnection *connection,
 const char *name,
 const char *path,
 const char *interface);
DBusGProxy* dbus_g_proxy_new_for_name_owner (DBusGConnection *connection,
 const char *name,
 const char *path,
 const char *interface,
 GError **error);
DBusGProxy* dbus_g_proxy_new_from_proxy (DBusGProxy *proxy,
 const char *interface,
 const char *path_name);
DBusGProxy* dbus_g_proxy_new_for_peer (DBusGConnection *connection,
 const char *path_name,
 const char *interface_name);
gboolean dbus_g_proxy_call (DBusGProxy *proxy,
 const char *method,
 GError **error,
 GType first_arg_type,
 ...);
gboolean dbus_g_proxy_call_with_timeout (DBusGProxy *proxy,
 const char *method,
 int timeout,
 GError **error,
 GType first_arg_type,
 ...);
DBusGProxyCall * dbus_g_proxy_begin_call (DBusGProxy *proxy,
 const char *method,
 DBusGProxyCallNotify notify,
 gpointer data,
 GDestroyNotify destroy,
 GType first_arg_type,
 ...);
DBusGProxyCall * dbus_g_proxy_begin_call_with_timeout (DBusGProxy *proxy,
 const char *method,
 DBusGProxyCallNotify notify,
 gpointer user_data,
 GDestroyNotify destroy,
 int timeout,
 GType first_arg_type,
 ...);
gboolean dbus_g_proxy_end_call (DBusGProxy *proxy,
 DBusGProxyCall *call,
 GError **error,
 GType first_arg_type,
 ...);
const char* dbus_g_proxy_get_path (DBusGProxy *proxy);
const char* dbus_g_proxy_get_bus_name (DBusGProxy *proxy);
const char* dbus_g_proxy_get_interface (DBusGProxy *proxy);
typedef struct _DBusGMethodInvocation DBusGMethodInvocation;
typedef struct {
 GCallback cb;
 gpointer userdata;
} DBusGAsyncData;
#endif
GType dbus_connection_get_g_type (void) G_GNUC_CONST;
GType dbus_message_get_g_type (void) G_GNUC_CONST;
GType dbus_pending_call_get_g_type (void) G_GNUC_CONST;
DBusConnection* dbus_g_connection_get_connection (DBusGConnection *gconnection);
DBusGConnection* dbus_connection_get_g_connection (DBusConnection *connection);
DBusMessage* dbus_g_message_get_message (DBusGMessage *gmessage);
gchar* dbus_g_method_get_sender (DBusGMethodInvocation *context);
DBusMessage* dbus_g_method_get_reply (DBusGMethodInvocation *context);
#endif
GType dbus_g_type_get_collection (const char *container,
 GType specialization);
GType dbus_g_type_get_map (const char *container,
 GType key_specialization,
 GType value_specialization);
GType dbus_g_type_get_structv (const char *container,
 guint num_members,
 GType *types);
GType dbus_g_type_get_struct (const char *container,
 GType first_type,
 ...);
gboolean dbus_g_type_is_collection (GType gtype);
gboolean dbus_g_type_is_map (GType gtype);
gboolean dbus_g_type_is_struct (GType gtype);
GType dbus_g_type_get_collection_specialization (GType gtype);
GType dbus_g_type_get_map_key_specialization (GType gtype);
GType dbus_g_type_get_map_value_specialization (GType gtype);
GType dbus_g_type_get_struct_member_type (GType gtype,
 guint member);
guint dbus_g_type_get_struct_size (GType gtype);
typedef void (*DBusGTypeSpecializedCollectionIterator) (const GValue *value,
 gpointer user_data);
typedef void (*DBusGTypeSpecializedMapIterator) (const GValue *key_val,
 const GValue *value_val,
 gpointer user_data);
gpointer dbus_g_type_specialized_construct (GType gtype);
typedef struct {
 GValue *val;
 GType specialization_type;
 gpointer b;
 guint c;
 gpointer d;
} DBusGTypeSpecializedAppendContext;
gboolean dbus_g_type_collection_get_fixed (GValue *value,
 gpointer *data,
 guint *len);
gboolean dbus_g_type_struct_get_member (const GValue *value,
 guint member,
 GValue *dest);
gboolean dbus_g_type_struct_set_member (GValue *value,
 guint member,
 const GValue *src);
gboolean dbus_g_type_struct_get (const GValue *value,
 guint member,
 ...);
gboolean dbus_g_type_struct_set (GValue *value,
 guint member,
 ...);
typedef gpointer (*DBusGTypeSpecializedConstructor) (GType type);
typedef void (*DBusGTypeSpecializedFreeFunc) (GType type, gpointer val);
typedef gpointer (*DBusGTypeSpecializedCopyFunc) (GType type, gpointer src);
typedef struct {
 DBusGTypeSpecializedConstructor constructor;
 DBusGTypeSpecializedFreeFunc free_func;
 DBusGTypeSpecializedCopyFunc copy_func;
 GDestroyNotify simple_free_func;
 gpointer padding2;
 gpointer padding3;
} DBusGTypeSpecializedVtable;
typedef gboolean (*DBusGTypeSpecializedCollectionFixedAccessorFunc) (GType type, gpointer instance, gpointer *values, guint *len);
typedef void (*DBusGTypeSpecializedCollectionIteratorFunc) (GType type, gpointer instance, DBusGTypeSpecializedCollectionIterator iterator, gpointer user_data);
typedef void (*DBusGTypeSpecializedCollectionAppendFunc) (DBusGTypeSpecializedAppendContext *ctx, GValue *val);
typedef void (*DBusGTypeSpecializedCollectionEndAppendFunc) (DBusGTypeSpecializedAppendContext *ctx);
typedef struct {
 DBusGTypeSpecializedVtable base_vtable;
 DBusGTypeSpecializedCollectionFixedAccessorFunc fixed_accessor;
 DBusGTypeSpecializedCollectionIteratorFunc iterator;
 DBusGTypeSpecializedCollectionAppendFunc append_func;
 DBusGTypeSpecializedCollectionEndAppendFunc end_append_func;
} DBusGTypeSpecializedCollectionVtable;
typedef void (*DBusGTypeSpecializedMapIteratorFunc) (GType type, gpointer instance, DBusGTypeSpecializedMapIterator iterator, gpointer user_data);
typedef void (*DBusGTypeSpecializedMapAppendFunc) (DBusGTypeSpecializedAppendContext *ctx, GValue *key, GValue *val);
typedef struct {
 DBusGTypeSpecializedVtable base_vtable;
 DBusGTypeSpecializedMapIteratorFunc iterator;
 DBusGTypeSpecializedMapAppendFunc append_func;
} DBusGTypeSpecializedMapVtable;
typedef gboolean (*DBusGTypeSpecializedStructGetMember) (GType type, gpointer instance, guint member, GValue *ret_value);
typedef gboolean (*DBusGTypeSpecializedStructSetMember) (GType type, gpointer instance, guint member, const GValue *new_value);
typedef struct {
 DBusGTypeSpecializedVtable base_vtable;
 DBusGTypeSpecializedStructGetMember get_member;
 DBusGTypeSpecializedStructSetMember set_member;
} DBusGTypeSpecializedStructVtable;
const DBusGTypeSpecializedMapVtable* dbus_g_type_map_peek_vtable (GType map_type);
const DBusGTypeSpecializedCollectionVtable* dbus_g_type_collection_peek_vtable (GType collection_type);
const DBusGTypeSpecializedMapVtable* dbus_g_type_map_peek_vtable (GType map_type);
const DBusGTypeSpecializedCollectionVtable* dbus_g_type_collection_peek_vtable (GType collection_type);
const DBusGTypeSpecializedStructVtable* dbus_g_type_struct_peek_vtable (GType struct_type);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
DBUS_MALLOC
DBUS_ALLOC_SIZE(1)
void* dbus_malloc (size_t bytes);
DBUS_MALLOC
DBUS_ALLOC_SIZE(1)
void* dbus_malloc0 (size_t bytes);
DBUS_MALLOC
DBUS_ALLOC_SIZE(2)
void* dbus_realloc (void *memory,
 size_t bytes);
typedef void (* DBusFreeFunction) (void *memory);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct DBusMessage DBusMessage;
typedef struct DBusMessageIter DBusMessageIter;
struct DBusMessageIter
{
 void *dummy1;
 void *dummy2;
 dbus_uint32_t dummy3;
 int dummy4;
 int dummy5;
 int dummy6;
 int dummy7;
 int dummy8;
 int dummy9;
 int dummy10;
 int dummy11;
 int pad1;
 int pad2;
 void *pad3;
};
DBusMessage* dbus_message_new (int message_type);
DBusMessage* dbus_message_new_method_call (const char *bus_name,
 const char *path,
 const char *interface,
 const char *method);
DBusMessage* dbus_message_new_method_return (DBusMessage *method_call);
DBusMessage* dbus_message_new_signal (const char *path,
 const char *interface,
 const char *name);
DBusMessage* dbus_message_new_error (DBusMessage *reply_to,
 const char *error_name,
 const char *error_message);
DBusMessage* dbus_message_new_error_printf (DBusMessage *reply_to,
 const char *error_name,
 const char *error_format,
 ...);
DBusMessage* dbus_message_copy (const DBusMessage *message);
DBusMessage* dbus_message_ref (DBusMessage *message);
int dbus_message_get_type (DBusMessage *message);
dbus_bool_t dbus_message_set_path (DBusMessage *message,
 const char *object_path);
const char* dbus_message_get_path (DBusMessage *message);
dbus_bool_t dbus_message_has_path (DBusMessage *message,
 const char *object_path);
dbus_bool_t dbus_message_set_interface (DBusMessage *message,
 const char *interface);
const char* dbus_message_get_interface (DBusMessage *message);
dbus_bool_t dbus_message_has_interface (DBusMessage *message,
 const char *interface);
dbus_bool_t dbus_message_set_member (DBusMessage *message,
 const char *member);
const char* dbus_message_get_member (DBusMessage *message);
dbus_bool_t dbus_message_has_member (DBusMessage *message,
 const char *member);
dbus_bool_t dbus_message_set_error_name (DBusMessage *message,
 const char *name);
const char* dbus_message_get_error_name (DBusMessage *message);
dbus_bool_t dbus_message_set_destination (DBusMessage *message,
 const char *destination);
const char* dbus_message_get_destination (DBusMessage *message);
dbus_bool_t dbus_message_set_sender (DBusMessage *message,
 const char *sender);
const char* dbus_message_get_sender (DBusMessage *message);
const char* dbus_message_get_signature (DBusMessage *message);
dbus_bool_t dbus_message_get_no_reply (DBusMessage *message);
dbus_bool_t dbus_message_is_method_call (DBusMessage *message,
 const char *interface,
 const char *method);
dbus_bool_t dbus_message_is_signal (DBusMessage *message,
 const char *interface,
 const char *signal_name);
dbus_bool_t dbus_message_is_error (DBusMessage *message,
 const char *error_name);
dbus_bool_t dbus_message_has_destination (DBusMessage *message,
 const char *bus_name);
dbus_bool_t dbus_message_has_sender (DBusMessage *message,
 const char *unique_bus_name);
dbus_bool_t dbus_message_has_signature (DBusMessage *message,
 const char *signature);
dbus_uint32_t dbus_message_get_serial (DBusMessage *message);
dbus_bool_t dbus_message_set_reply_serial (DBusMessage *message,
 dbus_uint32_t reply_serial);
dbus_uint32_t dbus_message_get_reply_serial (DBusMessage *message);
dbus_bool_t dbus_message_get_auto_start (DBusMessage *message);
dbus_bool_t dbus_message_get_path_decomposed (DBusMessage *message,
 char ***path);
dbus_bool_t dbus_message_append_args (DBusMessage *message,
 int first_arg_type,
 ...);
dbus_bool_t dbus_message_append_args_valist (DBusMessage *message,
 int first_arg_type,
 va_list var_args);
dbus_bool_t dbus_message_get_args (DBusMessage *message,
 DBusError *error,
 int first_arg_type,
 ...);
dbus_bool_t dbus_message_get_args_valist (DBusMessage *message,
 DBusError *error,
 int first_arg_type,
 va_list var_args);
dbus_bool_t dbus_message_contains_unix_fds (DBusMessage *message);
dbus_bool_t dbus_message_iter_init (DBusMessage *message,
 DBusMessageIter *iter);
dbus_bool_t dbus_message_iter_has_next (DBusMessageIter *iter);
dbus_bool_t dbus_message_iter_next (DBusMessageIter *iter);
char* dbus_message_iter_get_signature (DBusMessageIter *iter);
int dbus_message_iter_get_arg_type (DBusMessageIter *iter);
int dbus_message_iter_get_element_type (DBusMessageIter *iter);
#ifndef DBUS_DISABLE_DEPRECATED
DBUS_DEPRECATED int dbus_message_iter_get_array_len (DBusMessageIter *iter);
#endif
dbus_bool_t dbus_message_iter_append_basic (DBusMessageIter *iter,
 int type,
 const void *value);
dbus_bool_t dbus_message_iter_append_fixed_array (DBusMessageIter *iter,
 int element_type,
 const void *value,
 int n_elements);
dbus_bool_t dbus_message_iter_open_container (DBusMessageIter *iter,
 int type,
 const char *contained_signature,
 DBusMessageIter *sub);
dbus_bool_t dbus_message_iter_close_container (DBusMessageIter *iter,
 DBusMessageIter *sub);
dbus_bool_t dbus_set_error_from_message (DBusError *error,
 DBusMessage *message);
dbus_bool_t dbus_message_allocate_data_slot (dbus_int32_t *slot_p);
dbus_bool_t dbus_message_set_data (DBusMessage *message,
 dbus_int32_t slot,
 void *data,
 DBusFreeFunction free_data_func);
void* dbus_message_get_data (DBusMessage *message,
 dbus_int32_t slot);
int dbus_message_type_from_string (const char *type_str);
const char* dbus_message_type_to_string (int type);
dbus_bool_t dbus_message_marshal (DBusMessage *msg,
 char **marshalled_data_p,
 int *len_p);
DBusMessage* dbus_message_demarshal (const char *str,
 int len,
 DBusError *error);
int dbus_message_demarshal_bytes_needed (const char *str,
 int len);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
char* dbus_get_local_machine_id (void);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
DBusPendingCall* dbus_pending_call_ref (DBusPendingCall *pending);
dbus_bool_t dbus_pending_call_set_notify (DBusPendingCall *pending,
 DBusPendingCallNotifyFunction function,
 void *user_data,
 DBusFreeFunction free_user_data);
dbus_bool_t dbus_pending_call_get_completed (DBusPendingCall *pending);
DBusMessage* dbus_pending_call_steal_reply (DBusPendingCall *pending);
dbus_bool_t dbus_pending_call_allocate_data_slot (dbus_int32_t *slot_p);
dbus_bool_t dbus_pending_call_set_data (DBusPendingCall *pending,
 dbus_int32_t slot,
 void *data,
 DBusFreeFunction free_data_func);
void* dbus_pending_call_get_data (DBusPendingCall *pending,
 dbus_int32_t slot);
#endif
#ifdef __cplusplus
extern "C" {
#if 0
}
#endif
#endif
 DBUS_TYPE_BYTE_AS_STRING \
 DBUS_TYPE_BYTE_AS_STRING \
 DBUS_TYPE_BYTE_AS_STRING \
 DBUS_TYPE_BYTE_AS_STRING \
 DBUS_TYPE_UINT32_AS_STRING \
 DBUS_TYPE_UINT32_AS_STRING \
 DBUS_TYPE_ARRAY_AS_STRING \
 DBUS_STRUCT_BEGIN_CHAR_AS_STRING \
 DBUS_TYPE_BYTE_AS_STRING \
 DBUS_TYPE_VARIANT_AS_STRING \
 DBUS_STRUCT_END_CHAR_AS_STRING
#ifdef __cplusplus
#if 0
{
#endif
}
#endif
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct DBusServer DBusServer;
typedef void (* DBusNewConnectionFunction) (DBusServer *server,
 DBusConnection *new_connection,
 void *data);
DBusServer* dbus_server_listen (const char *address,
 DBusError *error);
DBusServer* dbus_server_ref (DBusServer *server);
dbus_bool_t dbus_server_get_is_connected (DBusServer *server);
char* dbus_server_get_address (DBusServer *server);
char* dbus_server_get_id (DBusServer *server);
dbus_bool_t dbus_server_set_watch_functions (DBusServer *server,
 DBusAddWatchFunction add_function,
 DBusRemoveWatchFunction remove_function,
 DBusWatchToggledFunction toggled_function,
 void *data,
 DBusFreeFunction free_data_function);
dbus_bool_t dbus_server_set_timeout_functions (DBusServer *server,
 DBusAddTimeoutFunction add_function,
 DBusRemoveTimeoutFunction remove_function,
 DBusTimeoutToggledFunction toggled_function,
 void *data,
 DBusFreeFunction free_data_function);
dbus_bool_t dbus_server_set_auth_mechanisms (DBusServer *server,
 const char **mechanisms);
dbus_bool_t dbus_server_allocate_data_slot (dbus_int32_t *slot_p);
dbus_bool_t dbus_server_set_data (DBusServer *server,
 int slot,
 void *data,
 DBusFreeFunction free_data_func);
void* dbus_server_get_data (DBusServer *server,
 int slot);
#endif
#ifdef __cplusplus
extern "C" {
#if 0
}
#endif
#endif
typedef enum
{
 DBUS_BUS_SESSION,
 DBUS_BUS_SYSTEM,
 DBUS_BUS_STARTER
} DBusBusType;
typedef enum
{
 DBUS_HANDLER_RESULT_HANDLED,
 DBUS_HANDLER_RESULT_NOT_YET_HANDLED,
 DBUS_HANDLER_RESULT_NEED_MEMORY
} DBusHandlerResult;
#ifdef __cplusplus
#if 0
{
#endif
}
#endif
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct
{
 void *dummy1;
 void *dummy2;
 dbus_uint32_t dummy8;
 int dummy12;
 int dummy17;
} DBusSignatureIter;
int dbus_signature_iter_get_current_type (const DBusSignatureIter *iter);
char * dbus_signature_iter_get_signature (const DBusSignatureIter *iter);
int dbus_signature_iter_get_element_type (const DBusSignatureIter *iter);
dbus_bool_t dbus_signature_iter_next (DBusSignatureIter *iter);
dbus_bool_t dbus_signature_validate (const char *signature,
 DBusError *error);
dbus_bool_t dbus_signature_validate_single (const char *signature,
 DBusError *error);
dbus_bool_t dbus_type_is_basic (int typecode);
dbus_bool_t dbus_type_is_container (int typecode);
dbus_bool_t dbus_type_is_fixed (int typecode);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef struct DBusMutex DBusMutex;
typedef struct DBusCondVar DBusCondVar;
typedef DBusMutex* (* DBusMutexNewFunction) (void);
typedef void (* DBusMutexFreeFunction) (DBusMutex *mutex);
typedef dbus_bool_t (* DBusMutexLockFunction) (DBusMutex *mutex);
typedef dbus_bool_t (* DBusMutexUnlockFunction) (DBusMutex *mutex);
typedef DBusMutex* (* DBusRecursiveMutexNewFunction) (void);
typedef void (* DBusRecursiveMutexFreeFunction) (DBusMutex *mutex);
typedef void (* DBusRecursiveMutexLockFunction) (DBusMutex *mutex);
typedef void (* DBusRecursiveMutexUnlockFunction) (DBusMutex *mutex);
typedef DBusCondVar* (* DBusCondVarNewFunction) (void);
typedef void (* DBusCondVarFreeFunction) (DBusCondVar *cond);
typedef void (* DBusCondVarWaitFunction) (DBusCondVar *cond,
 DBusMutex *mutex);
typedef dbus_bool_t (* DBusCondVarWaitTimeoutFunction) (DBusCondVar *cond,
 DBusMutex *mutex,
 int timeout_milliseconds);
typedef void (* DBusCondVarWakeOneFunction) (DBusCondVar *cond);
typedef void (* DBusCondVarWakeAllFunction) (DBusCondVar *cond);
typedef enum
{
 DBUS_THREAD_FUNCTIONS_MUTEX_NEW_MASK = 1 << 0,
 DBUS_THREAD_FUNCTIONS_MUTEX_FREE_MASK = 1 << 1,
 DBUS_THREAD_FUNCTIONS_MUTEX_LOCK_MASK = 1 << 2,
 DBUS_THREAD_FUNCTIONS_MUTEX_UNLOCK_MASK = 1 << 3,
 DBUS_THREAD_FUNCTIONS_CONDVAR_NEW_MASK = 1 << 4,
 DBUS_THREAD_FUNCTIONS_CONDVAR_FREE_MASK = 1 << 5,
 DBUS_THREAD_FUNCTIONS_CONDVAR_WAIT_MASK = 1 << 6,
 DBUS_THREAD_FUNCTIONS_CONDVAR_WAIT_TIMEOUT_MASK = 1 << 7,
 DBUS_THREAD_FUNCTIONS_CONDVAR_WAKE_ONE_MASK = 1 << 8,
 DBUS_THREAD_FUNCTIONS_CONDVAR_WAKE_ALL_MASK = 1 << 9,
 DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_NEW_MASK = 1 << 10,
 DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_FREE_MASK = 1 << 11,
 DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_LOCK_MASK = 1 << 12,
 DBUS_THREAD_FUNCTIONS_RECURSIVE_MUTEX_UNLOCK_MASK = 1 << 13,
 DBUS_THREAD_FUNCTIONS_ALL_MASK = (1 << 14) - 1
} DBusThreadFunctionsMask;
typedef struct
{
 unsigned int mask;
 DBusMutexNewFunction mutex_new;
 DBusMutexFreeFunction mutex_free;
 DBusMutexLockFunction mutex_lock;
 DBusMutexUnlockFunction mutex_unlock;
 DBusCondVarNewFunction condvar_new;
 DBusCondVarFreeFunction condvar_free;
 DBusCondVarWaitFunction condvar_wait;
 DBusCondVarWaitTimeoutFunction condvar_wait_timeout;
 DBusCondVarWakeOneFunction condvar_wake_one;
 DBusCondVarWakeAllFunction condvar_wake_all;
 DBusRecursiveMutexNewFunction recursive_mutex_new;
 DBusRecursiveMutexFreeFunction recursive_mutex_free;
 DBusRecursiveMutexLockFunction recursive_mutex_lock;
 DBusRecursiveMutexUnlockFunction recursive_mutex_unlock;
 void (* padding1) (void);
 void (* padding2) (void);
 void (* padding3) (void);
 void (* padding4) (void);
} DBusThreadFunctions;
dbus_bool_t dbus_threads_init (const DBusThreadFunctions *functions);
dbus_bool_t dbus_threads_init_default (void);
#endif
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#endif
typedef dbus_uint32_t dbus_unichar_t;
typedef dbus_uint32_t dbus_bool_t;
#endif
