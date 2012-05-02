#include "include/dbus-1.0/dbus/dbus.h"
#include "include/dbus-1.0/dbus/dbus-glib.h"
#include <string.h>

static const char *empty = "";

dbus_bool_t dbus_parse_address (const char *a,
 DBusAddressEntry ***b,
 int *c,
 DBusError *d) {
	return TRUE;
}

const char *dbus_address_entry_get_value (DBusAddressEntry *entry,
 const char *key) {
	return empty;
}

const char *dbus_address_entry_get_method (DBusAddressEntry *entry) {
	return empty;
}

char* dbus_address_escape_value (const char *value) {
	return NULL;
}

char* dbus_address_unescape_value (const char *value,
 DBusError *error) {
	return NULL;
}

DBusConnection *dbus_bus_get (DBusBusType type,
 DBusError *error) {
	return NULL;
}

DBusConnection *dbus_bus_get_private (DBusBusType type,
 DBusError *error) {
	return NULL;
}

dbus_bool_t dbus_bus_register (DBusConnection *connection,
 DBusError *error) {
	return TRUE;
}

dbus_bool_t dbus_bus_set_unique_name (DBusConnection *connection,
 const char *unique_name) {
	return TRUE;
}

const char* dbus_bus_get_unique_name (DBusConnection *connection) {
	return empty;
}

unsigned long dbus_bus_get_unix_user (DBusConnection *connection,
 const char *name,
 DBusError *error) {
	return 0;
}

char* dbus_bus_get_id (DBusConnection *connection,
 DBusError *error) {
	return strdup(empty);
}

int dbus_bus_request_name (DBusConnection *connection,
 const char *name,
 unsigned int flags,
 DBusError *error) {
	return DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER;
}

int dbus_bus_release_name (DBusConnection *connection,
 const char *name,
 DBusError *error) {
	return DBUS_RELEASE_NAME_REPLY_RELEASED;
}

dbus_bool_t dbus_bus_name_has_owner (DBusConnection *connection,
 const char *name,
 DBusError *error) {
	return TRUE;
}

dbus_bool_t dbus_bus_start_service_by_name (DBusConnection *connection,
 const char *name,
 dbus_uint32_t flags,
 dbus_uint32_t *reply,
 DBusError *error) {
	return TRUE;
}

DBusConnection* dbus_connection_open (const char *address,
 DBusError *error) {
	return NULL;
}

DBusConnection* dbus_connection_open_private (const char *address,
 DBusError *error) {
	return NULL;
}

DBusConnection* dbus_connection_ref (DBusConnection *connection) {
	return connection;
}

dbus_bool_t dbus_connection_get_is_connected (DBusConnection *connection) {
	return TRUE;
}

dbus_bool_t dbus_connection_get_is_authenticated (DBusConnection *connection) {
	return TRUE;
}

dbus_bool_t dbus_connection_get_is_anonymous (DBusConnection *connection) {
	return TRUE;
}

char* dbus_connection_get_server_id (DBusConnection *connection) {
	return strdup(empty);
}

dbus_bool_t dbus_connection_can_send_type (DBusConnection *connection,
 int type) {
	return TRUE;
}

dbus_bool_t dbus_connection_read_write_dispatch (DBusConnection *connection,
 int timeout_milliseconds) {
	return TRUE;
}

dbus_bool_t dbus_connection_read_write (DBusConnection *connection,
 int timeout_milliseconds) {
	return TRUE;
}

DBusMessage* dbus_connection_borrow_message (DBusConnection *connection) {
	return NULL;
}

DBusMessage* dbus_connection_pop_message (DBusConnection *connection) {
	return NULL;
}

DBusDispatchStatus dbus_connection_get_dispatch_status (DBusConnection *connection) {
	return DBUS_DISPATCH_COMPLETE;
}

DBusDispatchStatus dbus_connection_dispatch (DBusConnection *connection) {
	return DBUS_DISPATCH_COMPLETE;
}

dbus_bool_t dbus_connection_has_messages_to_send (DBusConnection *connection) {
	return FALSE;
}

dbus_bool_t dbus_connection_send (DBusConnection *connection,
 DBusMessage *message,
 dbus_uint32_t *client_serial) {
	return TRUE;
}

dbus_bool_t dbus_connection_send_with_reply (DBusConnection *connection,
 DBusMessage *message,
 DBusPendingCall **pending_return,
 int timeout_milliseconds) {
	return TRUE;
}

DBusMessage * dbus_connection_send_with_reply_and_block (DBusConnection *connection,
 DBusMessage *message,
 int timeout_milliseconds,
 DBusError *error) {
	return NULL;
}

dbus_bool_t dbus_connection_set_watch_functions (DBusConnection *connection,
 DBusAddWatchFunction add_function,
 DBusRemoveWatchFunction remove_function,
 DBusWatchToggledFunction toggled_function,
 void *data,
 DBusFreeFunction free_data_function) {
	return TRUE;
}

dbus_bool_t dbus_connection_set_timeout_functions (DBusConnection *connection,
 DBusAddTimeoutFunction add_function,
 DBusRemoveTimeoutFunction remove_function,
 DBusTimeoutToggledFunction toggled_function,
 void *data,
 DBusFreeFunction free_data_function) {
	return TRUE;
}

dbus_bool_t dbus_connection_get_unix_user (DBusConnection *connection,
 unsigned long *uid) {
	return FALSE;
}

dbus_bool_t dbus_connection_get_unix_process_id (DBusConnection *connection,
 unsigned long *pid) {
	return FALSE;
}

dbus_bool_t dbus_connection_get_adt_audit_session_data (DBusConnection *connection,
 void **data,
 dbus_int32_t *data_size) {
	return FALSE;
}

dbus_bool_t dbus_connection_get_windows_user (DBusConnection *connection,
 char **windows_sid_p) {
	return FALSE;
}

dbus_bool_t dbus_connection_add_filter (DBusConnection *connection,
 DBusHandleMessageFunction function,
 void *user_data,
 DBusFreeFunction free_data_function) {
	return TRUE;
}

dbus_bool_t dbus_connection_allocate_data_slot (dbus_int32_t *slot_p) {
	return TRUE;
}

dbus_bool_t dbus_connection_set_data (DBusConnection *connection,
 dbus_int32_t slot,
 void *data,
 DBusFreeFunction free_data_func) {
	return TRUE;
}

void* dbus_connection_get_data (DBusConnection *connection,
 dbus_int32_t slot) {
	return NULL;
}

long dbus_connection_get_max_message_size (DBusConnection *connection) {
	return 10;
}

long dbus_connection_get_max_received_size (DBusConnection *connection) {
	return 10;
}

long dbus_connection_get_max_message_unix_fds (DBusConnection *connection) {
	return 10;
}

long dbus_connection_get_max_received_unix_fds(DBusConnection *connection) {
	return 10;
}

long dbus_connection_get_outgoing_size (DBusConnection *connection) {
	return 0;
}

long dbus_connection_get_outgoing_unix_fds (DBusConnection *connection) {
	return 0;
}

DBusPreallocatedSend* dbus_connection_preallocate_send (DBusConnection *connection) {
	return NULL;
}

dbus_bool_t dbus_connection_try_register_object_path (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data,
 DBusError *error) {
	return TRUE;
}

dbus_bool_t dbus_connection_register_object_path (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data) {
	return TRUE;
}

dbus_bool_t dbus_connection_try_register_fallback (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data,
 DBusError *error) {
	return TRUE;
}

dbus_bool_t dbus_connection_register_fallback (DBusConnection *connection,
 const char *path,
 const DBusObjectPathVTable *vtable,
 void *user_data) {
	return TRUE;
}

dbus_bool_t dbus_connection_unregister_object_path (DBusConnection *connection,
 const char *path) {
	return TRUE;
}

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

DBUS_DEPRECATED int dbus_watch_get_fd (DBusWatch *watch);

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

dbus_bool_t dbus_error_has_name (const DBusError *error,
 const char *name);

dbus_bool_t dbus_error_is_set (const DBusError *error);

GType dbus_g_connection_get_g_type (void) G_GNUC_CONST;

GType dbus_g_message_get_g_type (void) G_GNUC_CONST;

DBusGConnection* dbus_g_connection_ref (DBusGConnection *connection);

DBusGMessage* dbus_g_message_ref (DBusGMessage *message);

GQuark dbus_g_error_quark (void);

gboolean dbus_g_error_has_name (GError *error,
 const char *name);

const char * dbus_g_error_get_name (GError *error);

DBusGConnection* dbus_g_connection_open (const gchar *address,
 GError **error);

DBusGConnection* dbus_g_bus_get (DBusBusType type,
 GError **error);

GObject * dbus_g_connection_lookup_g_object (DBusGConnection *connection,
 const char *at_path);

GType dbus_g_object_path_get_g_type (void) G_GNUC_CONST;

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

GType dbus_connection_get_g_type (void) G_GNUC_CONST;

GType dbus_message_get_g_type (void) G_GNUC_CONST;

GType dbus_pending_call_get_g_type (void) G_GNUC_CONST;

DBusConnection* dbus_g_connection_get_connection (DBusGConnection *gconnection);

DBusGConnection* dbus_connection_get_g_connection (DBusConnection *connection);

DBusMessage* dbus_g_message_get_message (DBusGMessage *gmessage);

gchar* dbus_g_method_get_sender (DBusGMethodInvocation *context);

DBusMessage* dbus_g_method_get_reply (DBusGMethodInvocation *context);

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

gpointer dbus_g_type_specialized_construct (GType gtype);

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

const DBusGTypeSpecializedMapVtable* dbus_g_type_map_peek_vtable (GType map_type);

const DBusGTypeSpecializedCollectionVtable* dbus_g_type_collection_peek_vtable (GType collection_type);

const DBusGTypeSpecializedMapVtable* dbus_g_type_map_peek_vtable (GType map_type);

const DBusGTypeSpecializedCollectionVtable* dbus_g_type_collection_peek_vtable (GType collection_type);

const DBusGTypeSpecializedStructVtable* dbus_g_type_struct_peek_vtable (GType struct_type);

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

DBUS_DEPRECATED int dbus_message_iter_get_array_len (DBusMessageIter *iter);

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

char* dbus_get_local_machine_id (void);

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

dbus_bool_t dbus_threads_init (const DBusThreadFunctions *functions);

dbus_bool_t dbus_threads_init_default (void);
