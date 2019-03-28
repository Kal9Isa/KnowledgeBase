class FontChooser extends React.Component {

		constructor(props) {
				super(props);
				this.state = {
						fweight: this.props.bold,
						fsize: Number(this.props.size),
						color: 'black',
						show: false
				};
			
				this.handleClick = this.handleClick.bind(this);
				this.handleChange = this.handleChange.bind(this);
				this.handleDecrease = this.handleDecrease.bind(this);
				this.handleIncrease = this.handleIncrease.bind(this);
				this.handleReset = this.handleReset.bind(this);
		}
		
	handleClick () {
			this.setState({show: !this.state.show});
	}

	handleChange () {
			if (this.state.fweight == true) {
				this.setState({fweight: false});
			}
			else {
				this.setState({fweight: true});
			}
	}

	handleDecrease () {
			if (this.state.fsize <= this.props.min) {
					this.setState({color: 'red'});
			}
			else {
					this.setState({color: 'black'});
					this.setState({fsize: this.state.fsize - 1});
			}
	}

	handleIncrease () {
			if (this.state.fsize >= this.props.max) {
					this.setState({color: 'red'});
			}
			else {
					this.setState({color: 'black'});
					this.setState({fsize: this.state.fsize + 1});
			}
	}

	handleReset () {
			this.setState({
					fsize: this.props.size,
					fweight: this.props.bold,
					color: 'black'
			});
	}

    render() {
		if (this.state.show == true) {
			return(
				<div>
					<input onClick={this.handleChange} type="checkbox" id="boldCheckbox"/>
					<button onClick={this.handleDecrease} id="decreaseButton" >-</button>
					<span id="fontSizeSpan">{this.state.fsize}</span>
					<button onClick={this.handleIncrease} id="increaseButton" >+</button>
					<span id="textSpan"
					style={{fontWeight: this.state.fweight? 'normal':'bold',
							fontSize: this.state.fsize,
							color: this.state.color}}
							onClick={this.handleClick}
							onDoubleClick={this.handleReset}>
					{this.props.text}</span>
				</div>
			);
		}
		else {
			return (
				<div>
					<span id="textSpan"
						style={{fontWeight: this.state.fweight? 'normal':'bold',
								fontSize: this.state.fsize,
								color: this.state.color? 'black':'red'}}
								onClick={this.handleClick}
								onDoubleClick={this.handleReset}>
					{this.props.text}</span>
				</div>				
			);
		}
    }
}

