const modelOptions = {
	toJSON: {
		virtuals: true,
		transform: (_, obj) => {
			delete obj._id;
			return obj;
		}
	},
	toObject: {
		virtuals: true,
		transform: (_, obj) => {
			delete obj._id;
			return obj;
		}
	},
	versionKey: false,
	timestamps: { createdAt: 'released', updatedAt: 'lastupdated' }
}

export default modelOptions;