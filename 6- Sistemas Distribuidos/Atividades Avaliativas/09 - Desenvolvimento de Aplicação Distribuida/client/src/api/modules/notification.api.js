import privateClient from '../client/private.client';

const notificationEndpoints = {
    fetchNotifications: '/notification',
    sendNotification: '/notification',
    deleteNotifications: '/notification',
}

const notificationApi = {
    fetchNotifications: async () => {
        try {
            const response = await privateClient.get(
                notificationEndpoints.fetchNotifications
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    sendNotification: async ({ content, receiverId, chatId }) => {
        try {
            const response = await privateClient.post(
                notificationEndpoints.sendNotification, {
                    content,
                    receiverId,
                    chatId
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    },

    deleteNotifications: async ({ chatId, receiverId }) => {
        try {
            const response = await privateClient.delete(
                notificationEndpoints.deleteNotifications, {
                    data: {
                        chatId,
                        receiverId
                    }
                }
            );
            return { response };
        } catch (error) {
            console.log(error);
            return { error };
        }
    }
}

export default notificationApi;